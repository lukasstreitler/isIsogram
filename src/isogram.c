#include "isogram.h"
#include <string.h>

bool is_isogram(const char phrase[]){

    int len = strlen(phrase);
    for (int i=0; i<len; i++) {
        char currentchar=phrase[i];
        int hits=0;
        for (int j=0; j<len; j++) {
             if(currentchar == phrase[j] && !(phrase[j] == " ") && !(currentchar == (phrase[j]+32)))
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
