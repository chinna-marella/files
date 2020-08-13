#include <stdio.h>
#define and &&
#define or ||
int length = 0, zero_count = 0, one_count = 0;


/*

================================= DESCRIPTION =====================================

The Acceptable strings of the language are 00, 11, 0111, 00100, 1011 .... etc. De-
terministic Finite Automata for the given language is given below 

M = (Q, E, delta, q0, F)
Q = set of all statest = (q0, q1, q2, q3, q4)
delta is transition function
E is alphabet = {0,1}
F = Final stats = (q2, q4)

And transitions are defined in below STATE DIAGRAM



================================= STATE DIAGRAM ===================================
                                                                                   
        --------                    --------                 --------              
	   |        |        0         |        |       0       |        | <----       
 ----> |   q0   |  ------------->  |   q1   |  -----------> |   q2   |      | 0    
	   |        |      --------->  |        | <------       |      A | -----       
	    --------      |             --------         |       --------              
		   |          |                |             |             |               
		   |          |          1     |             |             |               
		   |        0 |   -------------            0 |             |               
		 1 |          |  |                           |             |               
		   |          |  |                           |             |               
		   |          |  V                           |             |               
		   |		--------                   --------            |               
		   |	   |        |        1        |        | <-----    |               
			-----> |   q3   | --------------> |   q4   |       | 1 |               
				   |        |                 |      A | ------    |               
				    --------                   --------            |              
                       ^                                           |                             
					   |                1                          |               
					    -------------------------------------------
						
		STATES = (q0, q1, q2, q3, q4)
		
		START STATE = (q0)
		
		ACCEPTED STATES = (q2, q4)
		

++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                       +
====> ALGORITHM :                                      +
	INPUT :                                            +
		input --> {as a sring (like 0010)}             +
		                                               +
	OUTPUT:                                            +
		IF input is Acceptable then                    +
			prints --> {'String is accepted'}          +
		else                                           +
			prints --> {'Strint is not accepted'}      +
			                                           +
		IF input char is not in {1,0} then             +
			pirnts --> {'invaild input'}               +
			                                           +
++++++++++++++++++++++++++++++++++++++++++++++++++++++++


++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                       +
====> METHOD :                                         +
      INPUT -> {input}                                 +
	  length = len(INPUT)                              +
	                                                   +
	  IF length == 0 then                              +
	  	print("check in input")                        +
		                                               +
	  ELSE                                             +
	  		for i <- 0 to length-1 do                  +
				IF INPUT[i] not in {0,1}               +
					print("INVALID INPUT");            +
				ELSE                                   +
					CHECK_ACCEPTENCE(INPUT[i]);        +
					                                   +
					                                   +
    -----> CHECK_ACCEPTENCE(INPUT[i]) :                +
				IF i >= length-2 :                     +
					IF INPUT[i] in {0,1}               +
						INC count                      +
						                               +
++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/

// =============================== CODE FOR GIVEN QUESTION ==========================================

void CHECK_ACCEPTENCE(char, int);
void RESULT(void);

int main() {
    char INPUT[20];
    printf("Enter the string : ");
    scanf("%s",INPUT);
   
    while (INPUT[length] != '\0')
        length++;
   
    if (length == 0)
        printf("Check the input");
    else {
        for (int i = 0; i <= length-1; i++) {
            if (INPUT[i] == '1' or INPUT[i] == '0')
                CHECK_ACCEPTENCE(INPUT[i],i);
            else  {
                printf("Invaild input");
                break;
            }
        }
    }
   
    RESULT();
    return 0;
}

void CHECK_ACCEPTENCE(char bit, int i) {
    if (i >= length-2) {
        if (bit == '1')
            one_count++;
        else
            zero_count++;
	}
}

void RESULT(void) {
    if (zero_count == 2 or one_count == 2) 
        printf("\nGiven string is acceptable");
    else
        printf("\nGiven string is not acceptable");
}

