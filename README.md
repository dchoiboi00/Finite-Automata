# Finite-Automata
Implements deterministic and non-deterministic finite automata, as well as a NFA-DFA converter.

To create the executable file, use the terminal while in the project directory and run:  
	make

After that, run:
	./auto

My project does not have any memory leaks--all heap blocks were freed at exit.

**************************************
dfa.ch: DFA implementation  
nfa.ch: NFA implementation  
LinkedList.ch: LinkedList implementation (Prof. Ferguson)  
IntHashSet.ch: Hash set implementation (Prof. Ferguson)  
strdup.ch: (Prof. Ferguson)  

main.c: Contains  
	All functions for generating specific DFA/NFAs for the questions  
	READ_EVAL_PRINT_LOOP methods for DFA and NFA  
	NFA_to_DFA converter method  
	main() method
