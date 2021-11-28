#include "sort.h"

int get_max(Bucket b)
{
    if(is_empty(b)){
        return 0;
    }else{
        Bucket temp = b;
        int max = strlen(head(b));
        
        while(rest(temp)!=NULL){
            max = max < strlen(rest(temp)) ? max : strlen(rest(temp));
            temp=rest(temp);
        }
    }
}