#include <stdio.h>
#include <string.h>
#define MAXCHR 1000

/*
    written by Taner Durmaz
    This program is representation of DFA which accepts only even number of 1's
    input sequence must consist of 1's and 0's 
*/

int main(int argc, char **argv){
    enum STATES {A, B} state;
    char w[MAXCHR];
    int i;

    if (argc != 2) {
        printf("%s <w as binary string>\n", argv[0]);
        return -1;
    }
  
    strcpy(w, argv[1]);
  
    // starting state is A
    state = A;
    
    for (i=0; i<strlen(w); i++){
        switch(state){
            case A:
                if (w[i]== '0') {
                    state = A;
                }
                else{
                    state = B;
                }
                break;
            case B:
                if (w[i]== '0') {
                    state = B;
                }
                else{
                    state = A;
                }
                break;
        }
    }

    if (state == A)
        printf("accepted, sequence %s has even number of 1's \n", w);
    else
        printf("rejected, sequence %s has odd number of 1's  \n", w);
}
