//
//  main.c
//  Project 1
//
//  Created by Daniel Choi on 9/6/19.
//  Copyright © 2019 Daniel Choi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dfa.h"
#include "nfa.h"
#include "LinkedList.h"

//Exactly the string csc173
DFA* csc173() {
    DFA* this = new_DFA(7);
    DFA_set_transition(this, 0, 'c', 1);
    DFA_set_transition(this, 1, 's', 2);
    DFA_set_transition(this, 2, 'c', 3);
    DFA_set_transition(this, 0, 'C', 1);
    DFA_set_transition(this, 1, 'S', 2);
    DFA_set_transition(this, 2, 'C', 3);
    DFA_set_transition(this, 3, '1', 4);
    DFA_set_transition(this, 4, '7', 5);
    DFA_set_transition(this, 5, '3', 6);
    DFA_set_accepting(this, 6, true);
    return this;
}

//Any string that starts with the characters 'cat...'
DFA* cat() {
    DFA* this = new_DFA(4);
    DFA_set_transition(this, 0, 'c', 1);
    DFA_set_transition(this, 1, 'a', 2);
    DFA_set_transition(this, 2, 't', 3);
    DFA_set_transition(this, 0, 'C', 1);
    DFA_set_transition(this, 1, 'A', 2);
    DFA_set_transition(this, 2, 'T', 3);
    DFA_set_transition_all(this, 3, 3);
    DFA_set_accepting(this, 3, true);
    
    return this;
}

//Binary input with an even number of 0's
DFA* evenZeros() {
    DFA* this = new_DFA(3);
    DFA_set_transition(this, 0, '1', 0);
    DFA_set_transition(this, 0, '0', 1);
    DFA_set_transition(this, 1, '1', 1);
    DFA_set_transition(this, 1, '0', 2);
    DFA_set_transition(this, 2, '0', 1);
    DFA_set_transition(this, 2, '1', 2);
    DFA_set_accepting(this, 2, true);
    
    return this;
}

//Binary input with an even number of both 0's and 1's
DFA* evenZerosAndOnes(){
    DFA* this = new_DFA(9);
    DFA_set_transition(this, 0, '0', 1);
    DFA_set_transition(this, 0, '1', 2);
    DFA_set_transition(this, 1, '0', 3);
    DFA_set_transition(this, 1, '1', 4);
    DFA_set_transition(this, 3, '0', 1);
    DFA_set_transition(this, 2, '0', 4);
    DFA_set_transition(this, 2, '1', 5);
    DFA_set_transition(this, 5, '1', 2);
    DFA_set_transition(this, 3, '1', 6);
    DFA_set_transition(this, 4, '0', 6);
    DFA_set_transition(this, 6, '0', 4);
    DFA_set_transition(this, 4, '1', 7);
    DFA_set_transition(this, 7, '1', 4);
    DFA_set_transition(this, 5, '0', 7);
    DFA_set_transition(this, 6, '1', 8);
    DFA_set_transition(this, 8, '1', 6);
    DFA_set_transition(this, 7, '0', 8);
    DFA_set_transition(this, 8, '0', 7);
    DFA_set_accepting(this, 8, true);
    
    return this;
}

//Words starting with "dis.."
DFA* dis() {
    DFA* this = new_DFA(4);
    DFA_set_transition(this, 0, 'd', 1);
    DFA_set_transition(this, 1, 'i', 2);
    DFA_set_transition(this, 2, 's', 3);
    DFA_set_transition(this, 0, 'D', 1);
    DFA_set_transition(this, 1, 'I', 2);
    DFA_set_transition(this, 2, 'S', 3);
    DFA_set_transition_all(this, 3, 3);
    DFA_set_accepting(this, 3, true);
    
    return this;
}

//Strings that end with '..code'
NFA* endCode() {
    NFA* this = new_NFA(5);
    NFA_add_transition_all(this, 0, 0);
    NFA_add_transition(this, 0, 'c', 1);
    NFA_add_transition(this, 1, 'o', 2);
    NFA_add_transition(this, 2, 'd', 3);
    NFA_add_transition(this, 3, 'e', 4);
    NFA_set_accepting(this, 4, true);
    
    return this;
}

//Strings that contain "..code.."
NFA* containsCode() {
    NFA* this = new_NFA(5);
    NFA_add_transition_all(this, 0, 0);
    NFA_add_transition(this, 0, 'c', 1);
    NFA_add_transition(this, 1, 'o', 2);
    NFA_add_transition(this, 2, 'd', 3);
    NFA_add_transition(this, 3, 'e', 4);
    NFA_add_transition_all(this, 4, 4);
    NFA_set_accepting(this, 4, true);
    
    return this;
}

//Strings with more than one a, g, h, i, o, s, t, or w, or more than two n's
NFA* washington() {
    NFA* this = new_NFA(12);
    
    //3 is accepting state
    NFA_add_transition(this, 0, 'n', 1);
    NFA_add_transition(this, 1, 'n', 2);
    NFA_add_transition(this, 2, 'n', 3);
    NFA_add_transition(this, 0, 'a', 4);
    NFA_add_transition(this, 4, 'a', 3);
    NFA_add_transition(this, 0, 'g', 5);
    NFA_add_transition(this, 5, 'g', 3);
    NFA_add_transition(this, 0, 'h', 6);
    NFA_add_transition(this, 6, 'h', 3);
    NFA_add_transition(this, 0, 'i', 7);
    NFA_add_transition(this, 7, 'i', 3);
    NFA_add_transition(this, 0, 'o', 8);
    NFA_add_transition(this, 8, 'o', 3);
    NFA_add_transition(this, 0, 's', 9);
    NFA_add_transition(this, 9, 's', 3);
    NFA_add_transition(this, 0, 't', 10);
    NFA_add_transition(this, 10, 't', 3);
    NFA_add_transition(this, 0, 'w', 11);
    NFA_add_transition(this, 11, 'w', 3);
    
    //because the prompt is 'contains...' and this is an NFA
    for (int i = 0; i < 12; i++){
        NFA_add_transition_all(this, i, i);
    }
    
    NFA_set_accepting(this, 3, true);
    
    return this;
}

//Strings that end with '..ism'
NFA* ism() {
    NFA* this = new_NFA(4);
    NFA_add_transition_all(this, 0, 0);
    NFA_add_transition(this, 0, 'i', 1);
    NFA_add_transition(this, 1, 's', 2);
    NFA_add_transition(this, 2, 'm', 3);
    NFA_set_accepting(this, 3, true);
    
    return this;
}

//Helper function for Q3: Translator function
DFAState* newDFAState() {
    DFAState* this = (DFAState*)malloc(sizeof(DFAState));
    
    //initialize it like we do in dfa.c for new_DFA
    this->doesAccept = false;
    for (int i = 0; i < 128; i++){
        this->transitions[i] = -1;
    }
    return this;
}

//Question 3: Translator function, NFA to DFA
DFA* NFA_to_DFA(NFA* nfa){
    //Linkedlists to store our new DFA states, and sets that label those states
    LinkedList *DFA_states = new_LinkedList();
    LinkedList *DFA_sets_labels = new_LinkedList();
    
    //initialize both lists with 0
    int num_States = 1;   //number of states, also the number of next state to add
    DFAState* state_zero = newDFAState();
    LinkedList_add_at_front(DFA_states, state_zero);
    
    Set *initial_set_zero = new_Set(3);
    Set_insert(initial_set_zero, 0);
    LinkedList_add_at_front(DFA_sets_labels, initial_set_zero);
    
    
    //This iterator is VERY IMPORTANT. I tried using the LinkedListIterator, but the iterator would only iterate through the linkedlist it was given at its initialization. In other words, if I tried to LinkedList_add_at_end, the iterator would not receive that new input. It took me 3 and a half hours to solve this bug, until I found this iterator < num_States did the job.
    int iterator = 0;
    //While we have more dfa states to look at
    while (iterator < num_States) {
        DFAState* curr_state = LinkedList_elementAt(DFA_states, iterator);
        Set* curr_set_label = LinkedList_elementAt(DFA_sets_labels, iterator);
        
        //For every dfa state, look at all 128 input char possibilities. Create a new state with the appropriate set notation label if needed. Add it to the end of the linkedlist. Keep going until we have finished added all the needed dfa states.
        for (int i = 0; i < 128; i++) {
            Set* new_set_label = new_Set(255);   //this set notation label is for each char
            SetIterator *curr_set_label_iterator = Set_iterator(curr_set_label);
            while (SetIterator_hasNext(curr_set_label_iterator)){ //for every state in set
                int state = SetIterator_next(curr_set_label_iterator);
                Set_union(new_set_label, nfa->states[state].transitions[i]);
                //if at least one of the states are accepting, set dfa state to accepting
                if (nfa->states[state].doesAccept){
                    curr_state->doesAccept = true;
                }
            }
            free(curr_set_label_iterator);
            
            //Try to find the position of that set-label, since we need to link that transition. If we did not find the set-label, create a new state.
            int contains = -1;
            int state_number = 0;
            LinkedListIterator *search_iterator = LinkedList_iterator(DFA_sets_labels);
            while (LinkedListIterator_hasNext(search_iterator)) {
                Set *curr_set = LinkedListIterator_next(search_iterator);
                if (Set_equals(curr_set, new_set_label)) {  //if we found it
                    contains = state_number;
                }
                state_number++; //we did not find the set, increment state_number
            }
            free(search_iterator);
            
            //Make that transition backwards if we found the set, otherwise create a new state and add it to the linked lists
            if (contains < 0 && !(Set_isEmpty(new_set_label))) {
                DFAState* new_state = newDFAState();
                curr_state->transitions[i] = num_States;  //num_States is the correct number to make the new state, and link it to the current state
                LinkedList_add_at_end(DFA_states, new_state);
                LinkedList_add_at_end(DFA_sets_labels, new_set_label);
                num_States++;  //increment num_States
            } else if (!(Set_isEmpty(new_set_label))){
                curr_state->transitions[i] = contains;
                IntHashSet_free(new_set_label);  //this frees any set label that does not go into the linked list
            }
        }
        iterator++;
    }
    
    //After creating all of our dfa states, create and return the dfa
    DFA* this = new_DFA(num_States);
    LinkedListIterator *final_states = LinkedList_iterator(DFA_states);
    for (int i = 0; i < num_States; i++){
        DFAState* state = LinkedListIterator_next(final_states);
        this->states[i] = *state;
        free(state);
    }
    
    free(final_states);
    LinkedList_free(DFA_states, false); //this is false because we already freed the states
    LinkedList_free(DFA_sets_labels, true);  //this is true because we need to free the labels that were added to the linkedlist
    NFA_free(nfa);
    return this;
}

//READ-EVALUATE-PRINT-LOOP: DFA
void repl_DFA(char* name, DFA* dfa, char* input, char* quit, char* ask_for_input) {
    printf("\nTesting DFA that recognizes %s\n", name);
    DFA* this = dfa;
    do {
        printf("%s", ask_for_input);
        scanf("%255s", input);
        if (strcmp(input, quit) == 0){
            DFA_free(this);
            break;
        }
        bool b = DFA_execute(this, input);
        if (b) {
            printf("    Result for input \"%s\": true\n", input);
        } else {
            printf("    Result for input \"%s\": false\n", input);
        }
        
    } while (strcmp(input, quit) != 0);
}

//READ-EVALUATE-PRINT-LOOP: NFA
void repl_NFA(char* name, NFA *nfa, char* input, char* quit, char* ask_for_input) {
    printf("\nTesting NFA that recognizes %s\n", name);
    NFA *this = nfa;
    do {
        printf("%s", ask_for_input);
        scanf("%255s", input);
        if (strcmp(input, quit) == 0){
            NFA_free(this);
            break;
        }
        bool b = NFA_execute(this, input);
        if (b) {
            printf("    Result for input \"%s\": true\n", input);
        } else {
            printf("    Result for input \"%s\": false\n", input);
        }
    } while (strcmp(input, quit) != 0);
}

int main(int argc, char **argv) {
    char input[255];
    char quit[8];
    char ask_for_input[50];
    
    strcpy(quit, "quit");
    strcpy(ask_for_input, "    Enter an input (\"quit\" to quit): ");
    
    printf("CSC173 Project 1 by Yoo Choi\n");
    
    //Question 1: DFA
    repl_DFA("exactly \"csc173\"", csc173(), input, quit, ask_for_input);
    repl_DFA("strings that start with \"cat\"", cat(), input, quit, ask_for_input);
    repl_DFA("binary input with an even # of 0's", evenZeros(), input, quit, ask_for_input);
    repl_DFA("binary input with even #'s of 0's and 1's", evenZerosAndOnes(), input, quit, ask_for_input);
    repl_DFA("strings that start with \"dis..\"", dis(), input, quit, ask_for_input);

    //Question 2: NFA
    repl_NFA("strings ending in ..\"code\"", endCode(), input, quit, ask_for_input);
    repl_NFA("strings containing ..\"code\"..", containsCode(), input, quit, ask_for_input);
    repl_NFA("strings with more than one a, g, h, i, o, s, t, or w, or more than two n's", washington(), input, quit, ask_for_input);
    repl_NFA("strings ending in ..\"ism\"", ism(), input, quit, ask_for_input);

    //Question 3: NFA to DFA
    DFA* conv_dfa_endCode = NFA_to_DFA(endCode());
    DFA* conv_dfa_containsCode = NFA_to_DFA(containsCode());
    repl_DFA("strings ending in ..\"code\"", conv_dfa_endCode, input, quit, ask_for_input);
    repl_DFA("strings containing ..\"code\"..", conv_dfa_containsCode, input, quit, ask_for_input);
}
