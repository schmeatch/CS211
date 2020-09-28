#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
0 = alphabet
1 = digit
2 = operator
-1 = error (shouldnt happen tho)
*/

// letter checker
bool isLetter(char ch) {
    // uses the ASCII codes to compare and actually check if its a letter
    if( !( ((ch > 'a') && (ch < 'z')) || ((ch > 'A') && (ch < 'Z')) ) ) {
        return false;
    }
    return true;
}

// number check
bool isNumber(char ch) {
    // uses the ASCII codes to compare and actually check if its a number
    if( !( (ch > '0') && (ch < '9') )  ) {
        return false;
    }else{
        return true;
    }
}

//operators consist of no letters or numbers and are of length 3 chars or smaller *exception to sizeof operator
bool isOperator(char *str) {
    if (strcmp(str, "sizeof") ) {
        return true;
    }else if (strlen(str) > 3) {
        return false;
    }else{
        char currentchar = str[0];
        int i;
        for (i = 0; i < strlen(str); i++){
            currentchar = str[i];
            if( ( (currentchar > 'a') && (currentchar < 'z') ) || ( (currentchar > 'A') && (currentchar < 'Z') ) || ( (currentchar > '0') && (currentchar < '9') ) ) return false;
        }
    }
    return true;
}

// for now, i'm only adding in spaces, the other delims have to be added s00ntm
bool isDelim(char ch) {
    if(ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t' || ch == '\v' || ch == '\f') return true;
    return false;
}

void print(char *hold, int flag) {
    // multiple cases need........
    switch(flag) {
        case 0: // word 
            printf("word: \"%s\"\n", hold);
            break;
        case 1:
            printf("decimal integer: \"%s\"\n", hold);
            break;
        /*

        case #:
            printf("left parenthesis: \"%s\"\n", hold);
            break;
        case #:
            printf("right parenthesis: \"%s\"\n", hold);
            break;
        case #:
            printf("left bracket: \"%s\"\n", hold);
            break;
        case #:
            printf("right bracket: \"%s\"\n", hold);
            break;
        case #:
            printf("structure member: \"%s\"\n", hold);
            break;
        case #:
            printf("structure pointer: \"%s\"\n", hold);
            break;
         case #:
            printf("comma: \"%s\"\n", hold);
            break;
        case #:
            printf("negate: \"%s\"\n", hold);
            break;
        case #:
            printf("1s complement: \"%s\"\n", hold);
            break;
        case #:
            printf("shift right: \"%s\"\n", hold);
            break;
        case #:
            printf("shift left: \"%s\"\n", hold);
            break;
        case #:
            printf("bitwise XOR: \"%s\"\n", hold);
            break;
        case #:
            printf("bitwise OR: \"%s\"\n", hold);
            break;
        case #:
            printf("increment: \"%s\"\n", hold);
            break;
        case #:
            printf("decrement: \"%s\"\n", hold);
            break;
        case #:
            printf("addition: \"%s\"\n", hold);
            break;
        case #:
            printf("division: \"%s\"\n", hold);
            break;
        case #:
            printf("logical OR: \"%s\"\n", hold);
            break;
        case #:
            printf("logical AND: \"%s\"\n", hold);
            break;
        case #:
            printf("conditional true: \"%s\"\n", hold);
            break;
        case #:
            printf("conditional false: \"%s\"\n", hold);
            break;
        case #:
            printf("equality test: \"%s\"\n", hold);
            break;
        case #:
            printf("inequality test: \"%s\"\n", hold);
            break;
        case #:
            printf("less than test: \"%s\"\n", hold);
            break;
        case #:
            printf("greater than test: \"%s\"\n", hold);
            break;
        case #:
            printf("less than or equal test: \"%s\"\n", hold);
            break;
        case #:
            printf("greater than or equal test: \"%s\"\n", hold);
            break;
        case #:
            printf("assignment: \"%s\"\n", hold);
            break;
        case #:
            printf("plus equals: \"%s\"\n", hold);
            break;
        case #:
            printf("minus equals: \"%s\"\n", hold);
            break;
        case #:
            printf("times equals: \"%s\"\n", hold);
            break;
        case #:
            printf("divide equals: \"%s\"\n", hold);
            break;
        case #:
            printf("mod equals \"%s\"\n", hold);
            break;
        case #:
            printf("shift right equals: \"%s\"\n", hold);
            break;
        case #:
            printf("shift left equals: \"%s\"\n", hold);
            break;
        case #:
            printf("bitwise AND equals: \"%s\"\n", hold);
            break;
        case #:
            printf("bitwise XOR equals: \"%s\"\n", hold);
            break;
        case #:
            printf("bitwise OR equals: \"%s\"\n", hold);
            break;
        case #:
            printf("AND/address operator: \"%s\"\n", hold);
            break;
        case #:
            printf("minus/subtract operator: \"%s\"\n", hold);
            break;
        case #:
            printf("multiply/dereference operator: \"%s\"\n", hold);
            break;
        */
        default: // should never hit here
            break;
    }
}

int main (int argc, char **argv) { 
    // used to hold the temporary string and its flag (determines which type it is.)
    char *hold = malloc(sizeof(char) * strlen(argv[1]));
    char *last_hold = malloc(sizeof(char) * strlen(argv[1]));
    int flag;
    int count = 1;
    
    // to loop through every basic character (start small then expand)
    int i;
    for(i = 0; argv[1][i] != '\0'; i++) {
        // delim case
        if(isDelim(argv[1][i])) {
            if(strlen(hold) != 0) {
                // in this part, we need to figure out how to print out the what the thing is : "string". for now, i'm only implementing word
                print(hold, flag);

                // we want to reset the values of hold and flag 
                free(hold);
                free(last_hold);
                last_hold = malloc(sizeof(char) * strlen(argv[1]));
                hold = malloc(sizeof(char) * strlen(argv[1]));
                flag = -1;
                count = 1;
                continue;
            } else {
                continue;
            }
        }

        if(strlen(hold) == 0) {
            // flag determines the first character of the current token. 0 = word, 1 = digit, 2 = operator. we will do different operations based on that.
            if ( isLetter(argv[1][i]) ){
                flag = 0;
            }else if ( isNumber(argv[1][i]) ){
                flag = 1;
            }else{
                //operator
                flag = 2;
            }
            
            //asigns the first value and moves on
            hold[0] = argv[1][i];
            continue;
        } 

        if(strlen(hold) != 0) {
            hold[count] = argv[1][i];
            count++;

            // special case
            if(argv[1][i + 1] == '\0') print(hold, flag);
            continue;
        }


    }

    
}