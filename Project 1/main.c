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

//Exactly the string csc173
DFA csc173() {
    DFA this = new_DFA(7);
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
DFA cat() {
    DFA this = new_DFA(4);
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
DFA evenZeros() {
    DFA this = new_DFA(3);
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
DFA evenZerosAndOnes(){
    DFA this = new_DFA(9);
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
DFA dis() {
    DFA this = new_DFA(4);
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
NFA endCode() {
    NFA this = new_NFA(5);
    NFA_add_transition_all(this, 0, 0);
    NFA_add_transition(this, 0, 'c', 1);
    NFA_add_transition(this, 1, 'o', 2);
    NFA_add_transition(this, 2, 'd', 3);
    NFA_add_transition(this, 3, 'e', 4);
    NFA_set_accepting(this, 4, true);
    
    return this;
}

//Strings that contain "..code.."
NFA containsCode() {
    NFA this = new_NFA(5);
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
NFA washington() {
    NFA this = new_NFA(12);
    
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

//READ-EVALUATE-PRINT-LOOP: DFA
void repl_DFA(char* name, DFA dfa, char* input, char* quit, char* ask_for_input) {
    printf("\nTesting DFA that recognizes %s\n", name);
    do {
        printf("%s", ask_for_input);
        scanf("%255s", input);
        if (strcmp(input, quit) == 0){
            break;
        }
        DFA this = dfa;
        bool b = DFA_execute(this, input);
        if (b) {
            printf("    Result for input \"%s\": true\n", input);
        } else {
            printf("    Result for input \"%s\": false\n", input);
        }
        
    } while (strcmp(input, quit) != 0);
}

//READ-EVALUATE-PRINT-LOOP: NFA
void repl_NFA(char* name, NFA nfa, char* input, char* quit, char* ask_for_input) {
    printf("\nTesting NFA that recognizes %s\n", name);
    do {
        printf("%s", ask_for_input);
        scanf("%255s", input);
        if (strcmp(input, quit) == 0){
            break;
        }
        NFA this = nfa;
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
    char quit[10];
    char ask_for_input[100];
    
    strcpy(quit, "quit");
    strcpy(ask_for_input, "    Enter an input (\"quit\" to quit): ");
    
    printf("CSC173 Project 1 by Yoo Choi\n");
    
    //Question 1: DFA
//    repl_DFA("exactly \"csc173\"", csc173(), input, quit, ask_for_input);
//    repl_DFA("strings that start with \"cat\"", cat(), input, quit, ask_for_input);
//    repl_DFA("binary input with an even # of 0's", evenZeros(), input, quit, ask_for_input);
//    repl_DFA("binary input with even #'s of 0's and 1's", evenZerosAndOnes(), input, quit, ask_for_input);
//    repl_DFA("strings that start with \"dis..\"", dis(), input, quit, ask_for_input);
//
    //Question 2: NFA
    repl_NFA("strings ending in ..\"code\"", endCode(), input, quit, ask_for_input);
    repl_NFA("strings containing ..\"code\"..", containsCode(), input, quit, ask_for_input);
    repl_NFA("strings with more than one a, g, h, i, o, s, t, or w, or more than two n's", washington(), input, quit, ask_for_input);
}
