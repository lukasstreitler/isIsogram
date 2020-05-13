#include "isogram.h"
#include <string.h>

char toLowerCase(char c){
    if (c >= 'A' && c <= 'Z') {
        return c - ('A' - 'a');
    }
    return c;
}
bool isIgnored(char c) {
    return !(c>='0'&& c<='9'||c>='a'&& c<='z'||c>='A'&& c<='Z');
}

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

/*
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