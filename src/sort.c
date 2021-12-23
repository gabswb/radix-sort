#include "sort.h"

int max_length(Bucket b){
    if(is_empty(b)){
        return 0;
    }else{
        Bucket temp = b;
        int max = strlen(head(b));
        
        while(rest(temp)!=NULL){
            if(max<strlen(head(temp))){//max = max < strlen(head(temp)) ? max : strlen(rest(temp));
                max = strlen(head(temp));
            }
            temp=rest(temp);
        }
        return max;
    }
}

// Bucket sort(int base, Bucket l){
//     Bucket liste = l;
//     int max =  get_max(liste);

//     for()
// }