/* CS261- Assignment 1 - Q.3*/
/* Name: Wyatt Griffith
 * Date: 07/09/18
 * Solution description: main reads a string from the keyboard and passes it to cleanup and validateInput
 *                       validateInput determines if the input is valid, if so it passes to camelCase
 *                       cleanup and camelCase call toUppercase and toLowerCase
 *                       toUpperCase and toLowerCase make a single char upper or lower case
 *                       cleanup takes a string and puts it in the form word_otherword
 *                       camelCase takes a string in that form ^ and puts it in the form wordOtherword
 *                       main also prints the string after each function
 */

#include <stdio.h>
#include <stdlib.h>

char toUpperCase(char ch){
/*Convert ch to upper case, assuming it is in lower case currently*/
    if(ch > 96 && ch < 123)
        ch -= 32;
    return ch;
}

char toLowerCase(char ch){
/*Convert ch to lower case, assuming it is in upper case currently*/
    if(ch > 64 && ch < 91)
        ch += 32;
    return ch;
}

int stringLength(char s[]) {
/*Return the length of the string*/
    int len = 0;
    for(int i = 0; s[i] != 0; i++){
        len++;
    }
    return len;
}

void cleanUp(char* word){
    int length = stringLength(word);

/* Makes letters lowercase and other characters _ */
    for(int i = 0; i < length; i++){
        word[i] = toLowerCase(word[i]);
        if(word[i] < 97 || word[i] > 122){
            word[i] = '_';
        }
	}

/* Removes excess _ in a row */
    for(int i = 0; i < length; i++){
        while(word[i] == '_' && word[i+1] == '_'){
            for(int j = i; j < length; j++){
                word[j] = word[j+1];
            }
        }
	}

/* Removes all _ from beginning of word */
    while(word[0] == '_' ){
        for(int j = 0; j < length; j++){
            word[j] = word[j+1];
        }
    }
}

int validateInput(char* word){
    int isValid = 0;
    int length = stringLength(word);
    for(int i = 0; i < length; i++){
        if(word[i] == '_'){
            if(word[i+1] > 96 && word[i+1] < 123){
                if(word[i-1] > 96 && word[i-1] < 123)
                    isValid = 1;
            }
        }
    }
    return isValid;
}

void camelCase(char* word){
/*Convert to camelCase*/
	int length = stringLength(word);
	for(int i = 0; i < length; i++){
        if(word[i] == '_'){
            word[i] = toUpperCase(word[i+1]);
            for(int j = i+1; j < length; j++){
                word[j] = word[j+1];
            }
            length--;
        }
	}
}

int main(){
/*Read the string from the keyboard*/
    char theWord[] = "";
    printf("Please Enter Your String: ");
    scanf("%[^\n]%*c", theWord);
    printf("Your String: %s \n", theWord);

/*Prep string for camelCase*/
    cleanUp(theWord);
    printf("Clean String: %s \n", theWord);

/* Check String Validity */
/* If its Valid */
    if(validateInput(theWord) == 1){
/*Call camelCase*/
        camelCase(theWord);
/*Print the new string*/
        printf("New String: %s \n", theWord );
        return 0;
    }
/* If its invalid */
    else{
        printf("invalid input string");
        return 0;
    }
}
