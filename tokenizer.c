
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
    if( !( ((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z')) ) )   return false;
    return true;
}
// number check
bool isNumber(char ch) {
    // uses the ASCII codes to compare and actually check if its a number
    if( !( (ch >= '0') && (ch <= '9') )  )  return false;
        return true;
}
//operator check
bool isOperator(char ch) {
    if( (isNumber(ch)) || (isLetter(ch)) ) return false;
        return true;
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

//prints hold with token name dependant on flag
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
        case 44: 
            printf("octal integer: \"%s\"\n", hold);
            break;
        case 45: 
            printf("hexadecimal integer: \"%s\"\n", hold);
            break;
        case 46: 
            printf("floating point: \"%s\"\n", hold);
            break;
        case 47: // floating point but with e
            printf("floating point"" \"%s\"\n", hold);
        default: // should never hit here
            break;
    }
}

int main (int argc, char **argv) { 
    
    char *hold = malloc(sizeof(char) * strlen(argv[1]));
    char *last_held = malloc(sizeof(char) * strlen(argv[1]));
    char *temp = malloc(sizeof(char) * strlen(argv[1]));
    int hold_type;
    //hold/char types: 0-words, 1-nums, 2-ops -1 = delim
    int char_type;
    int flag;
    int count = 0;
    
    // to loop through every basic character (start small then expand)
    int i;
    for(i = 0; argv[1][i] != '\0'; i++) {
        //for every char get char type
        if (isLetter(argv[1][i]) ){
                char_type = 0;
        }else if ( isNumber(argv[1][i]) ){
                char_type = 1;
        }else if (isDelim(argv[1][i]) ){
                char_type = -1;
        }else{ //operator
                char_type = 2;
        }

        //CASE 2
        // delim or if types mismatch
        // print token and reset variables
        // only does something if hold is storing chars
        if(strlen(hold) > 0){
            //special case for operators
            //if current hold is not operator while last held is (for "+++" to become "++" and "+")
            if( ((whichOperator(last_held) != -1) && (whichOperator(hold) == -1)) ) { 

                //get flag operator
                flag = whichOperator(last_held);
                //print as normal
                print(last_held, flag);
                //removes last_held string from hold
                memmove(temp, hold + strlen(last_held), strlen(hold) - strlen(last_held));
                free(hold);
                hold = malloc(sizeof(char) * strlen(argv[1]));
                strcpy(hold,temp);
                free(temp);
                temp = malloc(sizeof(char) * strlen(argv[1]));
         
               
                //reset the values of last_held but keep hold and update values
                free(last_held);
                last_held = malloc(sizeof(char) * strlen(argv[1]));
                flag = whichOperator(hold);
                count = 1;

                
            //print if:
            //delim encountered
            //hold is word/number and operator encountered
            //hold is float and non period operator is encountered
            //hold is number and letter encountered(ignore for hex)
            //|| (flag == 46 && (char_type == 2) &&  argv[1][i] != '.')
            } else if((hold_type == 1) && (flag == 43) && (char_type == 0) // case used for letters after numerals
                    || (char_type == -1)  // case used for delims
                    || ((hold_type == 1) && (flag == 46) && (argv[1][i] == 'e') && (argv[1][i+1] == '\0')) // case for 2.1e
                    || ((hold_type == 1) && (flag == 46) && (argv[1][i] == 'e') && (argv[1][i+1] == '-') && (argv[1][i+2] == '\0')) // case for 2.1e-
                    || ((hold_type == 0) && (char_type == 2)) // case used for symbols after letters
                    || ((hold_type == 1) && (argv[1][i] == '.') && (argv[1][i + 1] == '\0')) // case used for "2." 
                    || ((hold_type == 1) && (flag == 43) && (char_type == 2) && (argv[1][i] != '.'))  // case used for symbols after numerals
                    || ((hold_type == 1) && (flag == 47) && (char_type == 2) && (argv[1][i] == '-') && (argv[1][i-1] != 'e')) // case for - in floating that isnt after 
                    || ((hold_type == 1) && (flag == 47) && (char_type == 2) && (argv[1][i] == '-') && (argv[1][i+1] == '\0'))
                    || ((hold_type == 2) && (char_type != 2))  // case used for non-symbols after symbols
                    || ((hold_type == 1) && (char_type == 0) && (flag != 45) && (argv[1][i] != 'e') && (flag != 44))) { // case used for words after floating values that aren't e thus not accepted


                if (hold_type == 2){
                    flag = whichOperator(hold);
                }

                //print token
                print(hold, flag);
                //reset the values of hold and flag 
                free(hold);
                free(last_held);
                last_held = malloc(sizeof(char) * strlen(argv[1]));
                hold = malloc(sizeof(char) * strlen(argv[1]));
                flag = -1;
                count = 0;
            
            }

        }
        
        //CASE 3
        //if hold is not empty and current char is not delim
        // store hold in last_held + update hold (append char)
        if(strlen(hold) != 0 && char_type != -1) {


            // this case is for floats that encounter a second . (i.e 1.42.)
            // we will print out the current hold then empty hold
            // we print out the single . and move on

            // float cases
            //if currently decimal and '.' encountered change to float
            if(hold_type == 1 && argv[1][i] == '.' && flag == 43 && argv[1][i+1] != '\0') {
                flag = 46;
            //if already float has ecountered '.' and now another '.'
            } else if(hold_type == 1 && argv[1][i] == '.' && flag == 46) {
                print(hold, flag);
                free(hold);
                hold = malloc(sizeof(char) * strlen(argv[1]));
                print(".", 5);
                count = 0;
                continue;
            //if  already float and encounter e : change print type to second type float
            } else if(hold_type == 1 && argv[1][i] == 'e' && flag == 46 && argv[1][i+1] != '\0') {
                flag = 47; // float case with exp.
                hold[count] = argv[1][i];
                count++;
                continue;

            //if already float with e and encounter e: print float and start new word token starting with e
            } else if(hold_type == 1 && argv[1][i] == 'e' && flag == 47) {
                print(hold, flag);
                free(hold);
                hold = malloc(sizeof(char) * strlen(argv[1]));
                count = 0;
                hold[count] = argv[1][i];
                count++;
                hold_type = 0;
                flag = 0;

                // special case
                if(argv[1][i + 1] == '\0') {
                    if (hold_type == 2){
                        flag = whichOperator(hold);
                    }
                    print(hold, flag);
                }
                continue;
            }
            
            
            // if 0 was passed in as first char of a token- check next char for possible: octal(44), hex(45), or dec(43)
            if (flag == 45 && count == 1){
                if ( (argv[1][i] >= '0') && (argv[1][i] <= '7') ){
                    //octal accepts any numbers after inital 0: 0-1
                    flag = 44; 
                }else if ( (argv[1][i] == 'x') ||  (argv[1][i] == 'X') ){
                    //hex next char has to be X or x
                    flag = 45;
                }else if ( (argv[1][i] == '8') ||  (argv[1][i] == '9') ){
                    //decimal if following char is 8 or 9 because that breaks the pattern for octal
                    flag = 43;              
                }
            }

            //special cases for octal/hex after the first nonzero
            if (flag == 44 && count > 1){
                //if octal can only recieve numbers <= 7 to continue octal pattern/otherwise it becomes decimal num
                if ( (argv[1][i] == '8') ||  (argv[1][i] == '9') ){
                    flag = 43;
                }
            }else if (flag == 45 && count > 1){
                //if hex pattern has been established (0x or 0X), the next chars can only be 0-9 or letters A-F
                if( ( ((argv[1][i] >= 'g') && (argv[1][i] <= 'z')) || ((argv[1][i] >= 'G') && (argv[1][i] <= 'Z')) ) ){
                    //(**if g-z encountered): print 0 as decimal, change flag/type to word
                    print("0",43);
                    flag = 0;
                    hold_type = 0;
                    memmove(hold, hold+1, strlen(hold));
                    count--;
                    
                }
            }

            last_held= strcpy(last_held,hold);
            hold[count] = argv[1][i];
            count++;
            
        }

        //CASE 1
         //if hold is empty and current char is not delim
        // we can add char to hold and specify hold_type
        if(strlen(hold) == 0 && char_type != -1) {
            if (isLetter(argv[1][i]) ){
                flag = 0;
                hold_type = 0;
            }else if ( isNumber(argv[1][i]) ){
                //check if 0 for octal/hex case
                if ((argv[1][i]) == '0'){
                    hold_type = 1;
                    flag = 45; //assume hex
                    
                }else{
                    hold_type = 1;
                    flag = 43; //otherwise set to dec
                }
            }else if (isOperator(argv[1][i]) ){
                //operator
                flag = 1;
                hold_type = 2;
            }

            //asigns the first value and moves on (count starts at 0 and after this is 1)
            hold[0] = argv[1][i];
            count++;

            
        
        } 

        // special case hits end
        if(argv[1][i + 1] == '\0') {
            
            if( ((whichOperator(last_held) != -1) && (whichOperator(hold) == -1)) ){ 
                //get flag operator
                flag = whichOperator(last_held);
                //print as normal
                print(last_held, flag);
                //removes last_held string from hold
                memmove(temp, hold + strlen(last_held), strlen(hold) - strlen(last_held));
                strcpy(hold,temp);
            }
            
            if (hold_type == 2){
                flag = whichOperator(hold);
            } else if(hold_type == 1 && strcmp(hold, "0") == 0) { // since we assumed 0 would cause a hexadecimal, we need to beware of this case.
                flag = 43;
            }

            print(hold, flag);
        }






    }

    
}
