# StateMachine

The included file is a c program that simulates a fsm starting with an initial set of states.



After running the file you can run several commands to cycle through or perform other tasks such as:

(After each tasks it also prints out the current state)

"p" : prints out all states.
e.g if the a b c is printed out on one line the state a has a 0 next value of b and a 1 next value of c

"0" : moves current state to the next 0 state

"1" : moves current state to the next 1 state

"c 0/1 A-H": this command changes the next 0/1 state of the current state to the specified A-H value which MUST BE CAPITALIZED
e.g if you want to change the next 0 state of the current state to a you should type "c 0 A"

"g" : this commmand collects all the garbage states (states which cannot be reached based on the current state of the machine) 
e.g if the current state is b, and next 0 and 1 are both b, all states except b are garbage.

"d" : deletes all garbage states

"d A-H" : deletes specified state (MUST BE CAPITALIZED) e.g if you wanted to delete the "c" state type "d C"
