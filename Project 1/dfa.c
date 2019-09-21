//
//  dfc.c
//  Project 1
//
//  Created by Daniel Choi on 9/15/19.
//  Copyright © 2019 Daniel Choi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dfa.h"



DFA* new_DFA(int nstates) {
    //create instance
    DFA* this = (DFA*)malloc(sizeof(DFA));
    if(this == NULL){
        return NULL;
    }
    
    //initialize DFA variables
    this->totalStates = nstates;
    this->states = (DFAState*)malloc(nstates*sizeof(DFAState));  //since we need space for all states, not just the first one we are pointing to
    this->currentState = 0;   //we start from 0
    
    //initialize DFAState variables
    for (int i = 0; i < nstates; i++){
        this->states[i].doesAccept = false;     //set all states as non-accepting
        for (int j = 0; j < 128; j++){
            this->states[i].transitions[j] = -1;   //a destination of -1 means 'no transition'
        }
    }
    
    return this;
}

void DFA_free(DFA *dfa){
    for (int i = 0; i < dfa->totalStates; i++){
        //free(dfa->states[i].transitions);  //no need for this since it was not dynamically allocated
    }
    free(dfa->states);     //free states
    free(dfa);
}

int DFA_get_size(DFA *dfa){
    return dfa->totalStates;
}

int DFA_get_transition(DFA *dfa, int src, char sym){
    return dfa->states[src].transitions[(int)sym];
}

void DFA_set_transition(DFA *dfa, int src, char sym, int dst){
    dfa->states[src].transitions[(int)sym] = dst;
}

void DFA_set_transition_str(DFA *dfa, int src, char *str, int dst){
    for (int i = 0; i < strlen(str); i++){
        dfa->states[src].transitions[(int)str[i]] = dst;
    }
}

void DFA_set_transition_all(DFA *dfa, int src, int dst){
    for (int i = 0; i < 128; i++){
        dfa->states[src].transitions[i] = dst;
    }
}

void DFA_set_accepting(DFA *dfa, int state, bool value){
    dfa->states[state].doesAccept = value;
}

bool DFA_get_accepting(DFA *dfa, int state){
    return dfa->states[state].doesAccept;
}

bool DFA_execute(DFA *dfa, char *input){
    for (int i = 0; i < strlen(input); i++) {
        int nextDest = dfa->states[dfa->currentState].transitions[(int)input[i]];
        if (nextDest == -1) {  //if no destination, the automaton rejects
            dfa->currentState = 0;   //reset to 0 before we return
            return false;
        } else {
            dfa->currentState = nextDest;  //update currentState, continue until end of 'input'
        }
    }
    
    //after we finish running through all chars in 'input'
    int finalState = dfa->currentState;
    dfa->currentState = 0;    //we have to reset to 0 after extracting to finalState
    if (DFA_get_accepting(dfa, finalState)) {
        return true;
    } else {
        return false;
    }
}
