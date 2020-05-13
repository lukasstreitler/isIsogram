#include "isogram.h"
#include <string.h>

char toLowerCase(char c){
    if (c >= 'A' && c <= 'Z') {
        return c - ('A' - 'a');
    }
    return c;
}
bool isanumber(char c)
{
    return(c>='0'&& c<='9');
}
bool isatallchar(char c)
{
    return (c>='A'&& c<='Z');
}
bool isasmallchar(char c)
{
    return (c>='a'&& c<='z');
}
bool isIgnored(char c) {
    return !( isanumber(c) || isasmallchar(c));
}
bool is_isogram(const char phrase[]){
    //count the occurences of all characters

    //see if all occurences are the same (or 0)

    // a = 2
    // b = 1
    // c = 0

    //     v
    // a a b c b b

    //occurences[65] means number of 'A's
    int occurences[256];  
    for (int i=0; i<256; i++) {
        occurences[i] = 0;
    }

    int len = strlen(phrase);
    for (int i=0; i<len; i++) {
        char currentChar = toLowerCase(phrase[i]);
        if (!isIgnored(currentChar)){
            //this character counts
            occurences[currentChar]++;
        }
    }

    //no we know the occurences of every character
    int expectedOccurence = -1;
    for(int i=0; i < 256; i++){
        if (!isIgnored((char)i)) {
            //we ignore if occurence[i] == 0
            if (occurences[i] != 0){
                if (expectedOccurence == -1){
                    // case 1 - this is the first time we see something != 0
                    expectedOccurence = occurences[i];
                }else{
                    // case 2 - we already saw something != 0
                    int currentOccurence = occurences[i];
                    if (currentOccurence != expectedOccurence){
                        return false;
                    }
                }
            }
        }
    }

    return true;
}
/*
bool is_isogram(const char phrase[]){
    int len = strlen(phrase);
    for (int i=0; i<len; i++) {
        char currentChar = toLowerCase(phrase[i]);
        
        if (!isIgnored(currentChar)){
            //check all other chars against currentChar
            //find if there are more than 1 occurences
            int occurences = 0;
            for(int j=0; j<len; j++){
                if (toLowerCase(phrase[j]) == currentChar) {
                    occurences++;
                }
            }
            if (occurences > 1) { //found duplicate characters --> no isogram
                return false;
            }
        }
        
        
    }
    // we didnt find duplicates, must be an isogram
    return true;
}


bool is_isogram(const char phrase[]){

    int len = strlen(phrase);
    for (int i=0; i<len; i++) {
        char currentchar=phrase[i];
        int hits=0;
        for (int j=0; j<len; j++) {
             if(currentchar == phrase[j] && !(phrase[j] == ' ') && !(currentchar == (phrase[j]-32)))
             {
                 hits++;
             }
        }
        if(hits>1)
        {
            return false;
        }
    }
    return true;
}
*/