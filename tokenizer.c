
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// checks if the current character is a alphabetical character
bool isLetter(char ch) {
    // uses the ASCII codes to compare and actually check if its a letter
    if( !( ((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z')) ) )   return false;
    return true;
}

// checks if the current character is a numeric character
bool isNumber(char ch) {
    // uses the ASCII codes to compare and actually check if its a number
    if( !( (ch >= '0') && (ch <= '9') )  )  return false;
        return true;
}
// checks if the current character is a operational character
bool isOperator(char ch) {
    // if its not a number of a letter, then it must be a operational character
    if( (isNumber(ch)) || (isLetter(ch)) ) return false;
        return true;
}
// delim check
bool isDelim(char ch) {
    // different white space coniditons
    if(ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t' || ch == '\v' || ch == '\f') return true;
    return false;
}

// Each operator will be assigned a specific flag in which this method will return to identify the current character.
// returns -1 if none of the operators match | this shouldnt ever hit.
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

// prints the current token based on the flag that we assigned it.
void print(char *hold, int flag) {
    switch(flag) {
        // case for words (i.e abc e743we)
        case 0: 
            printf("word: \"%s\"\n", hold);
            break;

        // 1 - 42 operators 
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
    
        // cases for numeric values
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
        // special case for floating values where it contains an e (i.e 3232.32e-10)
        case 47: 
            printf("floating point"" \"%s\"\n", hold);
        default: 
            break;
    }
}

int main (int argc, char **argv) { 
    
    // hold is a string used to hold the current token that is to be printed
    char *hold = malloc(sizeof(char) * strlen(argv[1]));

    // last_held is a string that holds the previous string value of hold. This is used for cases such as "+++" where it would be a increment and a addition operator.
    char *last_held = malloc(sizeof(char) * strlen(argv[1]));

    // I FORGET WHAT THIS IS, SKYLAR CHANGE LATER. <><><><><><><><><><><><><><>
    char *temp = malloc(sizeof(char) * strlen(argv[1]));

    // the token can be of 4 types: 0 - words, 1 - nums, 2 - ops, -1 - delims
    int hold_type;

    // the current character has 4 types: 0 - words, 1 - nums, 2 - ops, -1 - delims
    int char_type;

    // used to which token we're going to be printing (i.e right bracket... integer... floating value)
    int flag;

    // variable is used to keep track of where the character will be assigned in hold
    int count = 0;
    
    // to loop through every basic character and build the token
    int i;
    for(i = 0; argv[1][i] != '\0'; i++) {

        // every character will recieve a type.
        if (isLetter(argv[1][i]) ){
                char_type = 0;
        }else if ( isNumber(argv[1][i]) ){
                char_type = 1;
        }else if (isDelim(argv[1][i]) ){
                char_type = -1;
        }else{ //operator
                char_type = 2;
        }

        // condition 1a:
        /*
        This is condition will mostly be used to print the token when it either counters a delimiter or the types of the token and the current character mismatch.
        The current token (hold) will be printed to which then the values of the current token (hold) will be reset.
        It only does something if the current token is not empty.
        */
        if(strlen(hold) > 0){

            // operator case: if the current token (hold) type is not a operator while the last_hold type is. This is used for cases where (+++) becomes ("++") and ("+").
            if( ((whichOperator(last_held) != -1) && (whichOperator(hold) == -1)) ) { 

                // we need to determine which operator the token before the current character is added is.
                flag = whichOperator(last_held);

                //print as normal
                print(last_held, flag);

                //removes last_held string from hold
                memmove(temp, hold + strlen(last_held), strlen(hold) - strlen(last_held));
                
                // we want to reset the values of the token  <><><><><<><><><>
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

            // condition 1b:
            /*
            In this condition, the current token will be printed if a delimiter or a pattern mismatch occurs is encountered. 
            This will accounts for cases such as where the current token is a word/number and a operator is encountered or hold is a float and a non-period operator encountered.
            */
            } else if((hold_type == 1) && (flag == 43) && (char_type == 0) // special case 1: alphabetical characters are encountered while the current token type is numeric.
                    // special case 2: delimiters are encountered
                    || (char_type == -1)  
                    // special case 
                    // special case 3.1: floating values are raised to the value of e () but there is nothing after e. (i.e 2.0e)
                    || ((hold_type == 1) && (flag == 46) && (argv[1][i] == 'e') && (!(isNumber(argv[1][i+1])) || (argv[1][i+1] == '\0'))) 
                    // special case 3.2: floating values are raised to the value of e (-) but there is nothing after the e- (i.e 2.0e-) or a non-Numeric chacter is after e- (i.e 2.0e-A)
                    || ((hold_type == 1) && (flag == 46) && (argv[1][i] == 'e') && (argv[1][i+1] == '-') && ((argv[1][i+2] == '\0') || !(isNumber(argv[1][i+2]))))  
                    // special case 3.3: the operation "." is encountered while the token flag are integers thus making it a floating value but the character after "." is non-numeric.
                    || ((hold_type == 1) && (argv[1][i] == '.') && ((argv[1][i + 1] == '\0') || !(isNumber(argv[1][i+1])))) 
                    // special case 3.4: the operator "-" is encountered for floating values but it is not placed after the "e". (i.e 2.0e1-3)
                    || ((hold_type == 1) && (flag == 47) && (char_type == 2) && (argv[1][i] == '-') && (argv[1][i-1] != 'e'))
                    // special case 3.5: alphabetical characters other than e are encountered in floating values (i.e 2.1b3)  
                    || ((hold_type == 1) && (char_type == 0) && (flag != 45) && (argv[1][i] != 'e') && (flag != 44)) 
                    // special case 3.6 : operators are encountered after floats
                    || ((hold_type == 1) && (char_type == 2) && ((flag == 46) || (flag == 46)) && (isOperator(argv[1][i])))
                    // special case 4: operational characters are encountered while the current token type is alphabetical characters.
                    || ((hold_type == 0) && (char_type == 2)) 
                    // special case 5: operational characters are encountered while the current token type are numeric characters.
                    || ((hold_type == 1) && (flag == 43) && (char_type == 2) && (argv[1][i] != '.'))  
                    // <><><><><><><><><><><><><><><><><><><><><><>
                    || ((hold_type == 1) && (flag == 47) && (char_type == 2) && (argv[1][i] == '-') && (argv[1][i+1] == '\0')) 
                    // special case 7: non-operational characters are encountered while the current token type are operational characters.
                    || ((hold_type == 2) && (char_type != 2))) { 


                // determines which operator the current token type is if it is of type operational characters.
                if (hold_type == 2){
                    flag = whichOperator(hold);
                }

                //print token
                print(hold, flag);

                //reset the values of hold and flag  <><><><><><><><><><><><><><><><><><><><><><><
                free(hold);
                free(last_held);
                last_held = malloc(sizeof(char) * strlen(argv[1]));
                hold = malloc(sizeof(char) * strlen(argv[1]));
                flag = -1;
                count = 0;
            
            }

        }
    
        // Condition 2:
        /*
        This condition will be triggered if the current contents of the token are not empty while the current chraacter is not a delim. This would cause the character to be appended to the token should it hit the proper conditions.
        */
        if(strlen(hold) != 0 && char_type != -1) {

            // Condition block: Token is current a numeric character string --> it encounters a ".". These conditions will determine whether it becomes a floating value or it prints an integer and a operational character (i.e 2 . )

            // default case for floating values. if a "." is encountered 
            if(hold_type == 1 && argv[1][i] == '.' && flag == 43 && argv[1][i+1] != '\0') {
                flag = 46;
            // special case : the token is currently a float and it encounters another '.'
            } else if(hold_type == 1 && argv[1][i] == '.' && flag == 46) {
                print(hold, flag);
                free(hold);
                hold = malloc(sizeof(char) * strlen(argv[1]));
                print(".", 5);
                count = 0;
                continue;
            // special case : used to change the flags of the token. This will be a floating value with a expon 'e'.
            } else if(hold_type == 1 && argv[1][i] == 'e' && flag == 46 && argv[1][i+1] != '\0') {
                flag = 47; // float case with exp.
                hold[count] = argv[1][i];
                count++;
                continue;

            // special case: the flag of the current token is floating values with 'e' but it encounters another 'e'.
            } else if(hold_type == 1 && argv[1][i] == 'e' && flag == 47) {
                
                // We want to print the current token.
                print(hold, flag);

                // We want to clear up the contents of the current token then append in the 'e' that we encountered
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

        // Condition 3:
        /*
        This condition will be the first condition should the token be empty. It will append in the current character at the first slot and then determine the possible flag values of the token.
        */
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
