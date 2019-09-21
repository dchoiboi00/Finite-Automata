//
//  nfa.c
//  Project 1
//
//  Created by Daniel Choi on 9/15/19.
//  Copyright © 2019 Daniel Choi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nfa.h"
#include "LinkedList.h"

NFA* new_NFA(int nstates){
    //create instance
    NFA* this = (NFA*)malloc(sizeof(NFA));
    if(this == NULL){
        return NULL;
    }
    
    //initialize NFA variables
    this->totalStates = nstates;
    this->states = (NFAState*)malloc(nstates*sizeof(NFAState));  //since we need space for all states, not just the first one we are pointing to
    IntHashSet* initialstate = new_IntHashSet(3);
    Set_insert(initialstate, 0);
    this->currentStates = initialstate;   //we start from 0
    //IntHashSet_free(initialstate);
    
    //initialize NFAState variables
    for (int i = 0; i < nstates; i++){
        this->states[i].doesAccept = false;     //set all states as non-accepting
        for (int j = 0; j < 128; j++){
            this->states[i].transitions[j] = new_Set(30);   //instead of initializing as -1 (no destination), we make empty sets of size 50. An empty set means no transition
        }
    }
    
    return this;
}

void NFA_free(NFA *nfa){
    for (int i = 0; i < nfa->totalStates; i++){
        NFAState *curr_state = &nfa->states[i];
        for (int j = 0; j < 128; j++){
            Set_free(curr_state->transitions[j]);   //free every set in the set array
        }
    }
    if (!Set_isEmpty(nfa->currentStates)){
        Set_free(nfa->currentStates);
    }
    free(nfa->states);
    free(nfa);
}

int NFA_get_size(NFA *nfa){
    return nfa->totalStates;
}

Set* NFA_get_transitions(NFA *nfa, int state, char sym){
    return nfa->states[state].transitions[(int)sym];
}

void NFA_add_transition(NFA *nfa, int src, char sym, int dst){
    Set_insert(nfa->states[src].transitions[(int)sym], dst);
}

void NFA_add_transition_all(NFA *nfa, int src, int dst){
    for (int i = 0; i < 128; i++) {
        Set_insert(nfa->states[src].transitions[i], dst);
    }
}

void NFA_set_accepting(NFA *nfa, int state, bool value){
    nfa->states[state].doesAccept = value;
}

bool NFA_get_accepting(NFA *nfa, int state){
    return nfa->states[state].doesAccept;
}

bool NFA_execute(NFA *nfa, char *input){
    //keep updating our set of states for each input character
    int i = 0;   //iterator for input string
    int state;    //iterator for each possible state in currentStates
    LinkedList* temp_states = new_LinkedList();   //list of states while we compare, so we can free as a whole later
    LinkedList_add_at_front(temp_states, nfa->currentStates);
    while (input[i] != '\0') {  //stops at termination of string 'input'
        Set* updated_currentStates = new_Set(30);  //our basket
        SetIterator* possible_states_iterator = Set_iterator(LinkedList_elementAt(temp_states, 0));
        while (SetIterator_hasNext(possible_states_iterator)){
            state = SetIterator_next(possible_states_iterator);
            Set_union(updated_currentStates, nfa->states[state].transitions[(int)input[i]]);
        }
        Set* temp = new_Set(30);
        IntHashSet_union(temp, updated_currentStates);  //dump the basket into a temp set, to put in the linked list, because we will free the entire list later
        LinkedList_add_at_front(temp_states, temp);
        IntHashSet_free(updated_currentStates);   //free our basket
        i++;
        free(possible_states_iterator);
    }
    nfa->currentStates = LinkedList_pop(temp_states);  //this is our final set of states
    LinkedList_free(temp_states, true);   //freed everything
    
    
    //check our final set of states to see if any are in accepting states
    int final_state;
    SetIterator *check_for_accepting = Set_iterator(nfa->currentStates);
    while (SetIterator_hasNext(check_for_accepting)){
        final_state = SetIterator_next(check_for_accepting);
        if (nfa->states[final_state].doesAccept){
            free(check_for_accepting);
            return true;
        }
    }
    //if not accepting
    free(check_for_accepting);
    return false;
}
