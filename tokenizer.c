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

//operator check
bool isOperator(char ch) {
    
    if( (isNumber(ch)) || (isLetter(ch)) ){
        return false;
    }else{
        return true;
    }
    
}

// delim check
bool isDelim(char ch) {
    if(ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t' || ch == '\v' || ch == '\f') return true;
    return false;
}

//RETURNS FLAG OF OPERATOR - returns -1 for not operator
int whichOperator(char *str){
    if( strcmp(str,"(") == 0){
        return 1;
    }else if ( strcmp(str,")") == 0){ 
        return 2;
    }else if ( strcmp(str,"[") == 0){ 
        return 3;
    }else if ( strcmp(str,"]") == 0){ 
        return 4;
    }else if ( strcmp(str,".") == 0){ 
        return 5;
    }else if ( strcmp(str,"->") == 0){ 
        return 6;
    }else if ( strcmp(str,"sizeof") == 0){ 
        return 7;
    }else if ( strcmp(str,",") == 0){ 
        return 8;
    }else if ( strcmp(str,"!") == 0){ 
        return 9;
    }else if ( strcmp(str,"~") == 0){ 
        return 10;
    }else if ( strcmp(str,">>") == 0){ 
        return 11;
    }else if ( strcmp(str,"<<") == 0){ 
        return 12;
    }else if ( strcmp(str,"^") == 0){ 
        return 13;
    }else if ( strcmp(str,"|") == 0){ 
        return 14;
    }else if ( strcmp(str,"++") == 0){ 
        return 15;
    }else if ( strcmp(str,"--") == 0){ 
        return 16;
    }else if ( strcmp(str,"+") == 0){ 
        return 17;
    }else if ( strcmp(str,"/") == 0){ 
        return 18;
    }else if ( strcmp(str,"||") == 0){ 
        return 19;
    }else if ( strcmp(str,"&&") == 0){ 
        return 20;
    }else if ( strcmp(str,"?") == 0){ 
        return 21;
    }else if ( strcmp(str,":") == 0){ 
        return 22;
    }else if ( strcmp(str,"==") == 0){ 
        return 23;
    }else if ( strcmp(str,"!=") == 0){ 
        return 24;
    }else if ( strcmp(str,"<") == 0){ 
        return 25;
    }else if ( strcmp(str,">") == 0){ 
        return 26;
    }else if ( strcmp(str,"<=") == 0){ 
        return 27;
    }else if ( strcmp(str,">=") == 0){ 
        return 28;
    }else if ( strcmp(str,"=") == 0){ 
        return 29;
    }else if ( strcmp(str,"+=") == 0){ 
        return 30;
    }else if ( strcmp(str,"-=") == 0){ 
        return 31;
    }else if ( strcmp(str,"*=") == 0){ 
        return 32;
    }else if ( strcmp(str,"/=") == 0){ 
        return 33;
    }else if ( strcmp(str,"%=") == 0){ 
        return 34;
    }else if ( strcmp(str,">>=") == 0){ 
        return 35;
    }else if ( strcmp(str,"<<=") == 0){ 
        return 36;
    }else if ( strcmp(str,"&=") == 0){ 
        return 37;
    }else if ( strcmp(str,"^=") == 0){ 
        return 38;
    }else if ( strcmp(str,"|=") == 0){ 
        return 39;
    }else if ( strcmp(str,"&") == 0){ 
        return 40;
    }else if ( strcmp(str,"-") == 0){ 
        return 41;
    }else if ( strcmp(str,"*") == 0){ 
        return 42;
    }else{
        return -1;
    }
    
        
    
}


void print(char *hold, int flag) {
    // multiple cases need........
    switch(flag) {
        case 0: // word 
            printf("word: \"%s\"\n", hold);
            break;

           //1 - 42 operators 
        case 1:
            printf("left parenthesis: \"%s\"\n", hold);
            break;
        case 2:
            printf("right parenthesis: \"%s\"\n", hold);
            break;
        case 3:
            printf("left bracket: \"%s\"\n", hold);
            break;
        case 4:
            printf("right bracket: \"%s\"\n", hold);
            break;
        case 5:
            printf("structure member: \"%s\"\n", hold);
            break;
        case 6:
            printf("structure pointer: \"%s\"\n", hold);
            break;
        case 7:
            printf("sizeof: \"%s\"\n", hold);
            break;
         case 8:
            printf("comma: \"%s\"\n", hold);
            break;
        case 9:
            printf("negate: \"%s\"\n", hold);
            break;
        case 10:
            printf("1s complement: \"%s\"\n", hold);
            break;
        case 11:
            printf("shift right: \"%s\"\n", hold);
            break;
        case 12:
            printf("shift left: \"%s\"\n", hold);
            break;
        case 13:
            printf("bitwise XOR: \"%s\"\n", hold);
            break;
        case 14:
            printf("bitwise OR: \"%s\"\n", hold);
            break;
        case 15:
            printf("increment: \"%s\"\n", hold);
            break;
        case 16:
            printf("decrement: \"%s\"\n", hold);
            break;
        case 17:
            printf("addition: \"%s\"\n", hold);
            break;
        case 18:
            printf("division: \"%s\"\n", hold);
            break;
        case 19:
            printf("logical OR: \"%s\"\n", hold);
            break;
        case 20:
            printf("logical AND: \"%s\"\n", hold);
            break;
        case 21:
            printf("conditional true: \"%s\"\n", hold);
            break;
        case 22:
            printf("conditional false: \"%s\"\n", hold);
            break;
        case 23:
            printf("equality test: \"%s\"\n", hold);
            break;
        case 24:
            printf("inequality test: \"%s\"\n", hold);
            break;
        case 25:
            printf("less than test: \"%s\"\n", hold);
            break;
        case 26:
            printf("greater than test: \"%s\"\n", hold);
            break;
        case 27:
            printf("less than or equal test: \"%s\"\n", hold);
            break;
        case 28:
            printf("greater than or equal test: \"%s\"\n", hold);
            break;
        case 29:
            printf("assignment: \"%s\"\n", hold);
            break;
        case 30:
            printf("plus equals: \"%s\"\n", hold);
            break;
        case 31:
            printf("minus equals: \"%s\"\n", hold);
            break;
        case 32:
            printf("times equals: \"%s\"\n", hold);
            break;
        case 33:
            printf("divide equals: \"%s\"\n", hold);
            break;
        case 34:
            printf("mod equals \"%s\"\n", hold);
            break;
        case 35:
            printf("shift right equals: \"%s\"\n", hold);
            break;
        case 36:
            printf("shift left equals: \"%s\"\n", hold);
            break;
        case 37:
            printf("bitwise AND equals: \"%s\"\n", hold);
            break;
        case 38:
            printf("bitwise XOR equals: \"%s\"\n", hold);
            break;
        case 39:
            printf("bitwise OR equals: \"%s\"\n", hold);
            break;
        case 40:
            printf("AND/address operator: \"%s\"\n", hold);
            break;
        case 41:
            printf("minus/subtract operator: \"%s\"\n", hold);
            break;
        case 42:
            printf("multiply/dereference operator: \"%s\"\n", hold);
            break;
        //operators over
        case 43: 
            printf("decimal integer: \"%s\"\n", hold);
            break;
        default: // should never hit here
            break;
    }
}

int main (int argc, char **argv) { 
    // used to hold the temporary string and its flag (determines which type it is.)
    char *hold = malloc(sizeof(char) * strlen(argv[1]));
    char *last_hold = malloc(sizeof(char) * strlen(argv[1]));
    int hold_type;
    //hold types: 0-words, 1-nums, 2-ops -1 = delim
    int char_type;
    int flag;
    int count = 1;
    
    // to loop through every basic character (start small then expand)
    int i;
    for(i = 0; argv[1][i] != '\0'; i++) {

 
        //for every char get char type
        if ( isLetter(argv[1][i]) ){
                char_type = 0;
        }else if ( isNumber(argv[1][i]) ){
                char_type = 1;
        }else if (isDelim(argv[1][i]) ){
                char_type = -1;
        }else{ //operator
                char_type = 2;
        }
        /////////////////////////////////
       // printf("(%c:",argv[1][i]);
       // printf("%ld)",strlen(hold));
       // printf("-%d",char_type);
        //////////////////////////////////

        

        // delim or if types mismatch
        // only does something if hold has something inside
        if(strlen(hold)>0){
            if((hold_type == 2) && (char_type != 2)){ 
                //get flag operator
               
                flag = whichOperator(hold);
                //print as normal
                print(hold, flag);

                // we want to reset the values of hold and flag 
                free(hold);
                free(last_hold);
                last_hold = malloc(sizeof(char) * strlen(argv[1]));
                hold = malloc(sizeof(char) * strlen(argv[1]));
                flag = -1;
                count = 1;
                continue;
            }else if(isDelim(argv[1][i]) || ((hold_type == 0) && (char_type == 2)) || ((hold_type == 1) && (char_type == 2)) || ((hold_type == 0) && (char_type == 1))) {
            
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
            
            }
        }
        

        if(strlen(hold) == 0) {
            // flag determines the first character of the current token. 0 = word, 1 = digit, 2 = operator. we will do different operations based on that.
            if (isLetter(argv[1][i]) ){
                flag = 0;
                hold_type = 0;
            }else if ( isNumber(argv[1][i]) ){
                flag = 43;
                hold_type = 1;
            }else if (isOperator(argv[1][i]) ){
                
                //operator
                flag = 1;
                hold_type = 2;
            }
            /////////////////////////////////
            //printf("+%d",hold_type);
            //////////////////////////////////
            
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
