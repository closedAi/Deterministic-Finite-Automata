#include <stdio.h>
#include <string.h>
#define MAXCHR 1000
typedef int bool;
#define true 1
#define false 0
/*
    written by Taner Durmaz
    contact: taner.durmaz.cs@gmail.com
*/

//Accepts only even number of 1's
bool even1s(){
    char w[MAXCHR];
    enum STATES {A, B} state;
    printf("Enter the string \n");
    scanf("%s", w);
    
    // starting state is A
    state = A;
  
    for (int i = 0; i<strlen(w); i++){
        switch(state){
            case A:
                if (w[i]== '1') {
                    state = B;
                }
                else{
                    state = A;
                }
                break;
            case B:
                if (w[i]== '1') {
                    state = A;
                }
                else{
                    state = B;
                }
                break;
        }
    }

    if (state == A){
        printf("accepted, sequence %s has even number of 1's \n", w);
        return true;
    }
    else{
        printf("rejected, sequence %s has odd number of 1's  \n", w);
        return false;
    }
}

int main(int argc){
    int dfaNo;
    do{
        printf("Available DFA\n");
        printf("0 Exit\n");
        printf("1 Accept even number of 1's\n");
        printf("----------------------------\n");
        printf("Choose DFA\n");
        scanf("%d", &dfaNo);
        if(dfaNo == 1){
            even1s();
        }
        else{
            printf("Invalid input try again\n");
        }
    }while(dfaNo != 0);
    
    return 0;
}

