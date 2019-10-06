
CSC173 
Project 1: Finite Automata
Yoo Choi, ychoi42@u.rochester.edu
Due September 23, 2019
I did not work with any other members on this project.

To create the executable file, use the terminal while in the project directory and run:
	make

After that, run:
	./auto

My project does not have any memory leaks--all heap blocks were freed at exit.

Note: If you are running valgrind on the Rochester CSUG cycles, and you 'scp' the folder that already ran the makefile, you may encounter an error where nfa.o is not recognized. If this is the case, run (on the cycle terminal):
	rm nfa.o
	make
	valgrind ./auto

**************************************
dfa.ch: DFA implementation
nfa.ch: NFA implementation
LinkedList.ch: Prof. Ferguson's code
IntHashSet.ch: Prof. Ferguson's code
strdup.ch: Prof. Ferguson's code
main.c: Contains:
	All functions for generating specific DFA/NFAs for the questions
	READ_EVAL_PRINT_LOOP methods for DFA and NFA
	NFA_to_DFA converter method
	main() method
