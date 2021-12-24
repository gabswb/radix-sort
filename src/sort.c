#include "sort.h"

int max_length_bucket(Bucket b){
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

int max_length(char** array, int size)
{
    int max = 0;
    for(int i=1; i<size;i++){ /** On commence à i=1 car argv[0] contient le nom du programme **/
        if(max< strlen(array[i]))
            max = strlen(array[i]);
    }
    return max;
}



Bucket sort(int base, int max, Bucket l)
{
    printf("start\n");
    Bucket list = l;
    Bucket* bucket_list = malloc(base*sizeof(Bucket)); 
    if(bucket_list==NULL) exit(EXIT_FAILURE);

    for(int i = 0; i<base; i++){
        bucket_list[i] = create();
    }

    for(int i = max-1; i>=0; i--){
        while(!is_empty(list)){
            printf("while\n");
            printf("i=%d, head(list)= %c\n", i, head(list)[i]);
            insert_bucket_list(bucket_list, list, head(list)[i]);                            /** bucket_list[(int) head(list)[i]] = insert_tail(bucket_list[(int) head(list)[i]], head(list));**/
            printf("insert_bucket_list\n");
            list = remove_head(list);
            
            for(int k=0; k<base;k++){
                printf(" bucket[%d] : ",k);
                print_bucket(bucket_list[k]);
            }
            printf("\n");
            printf("list : ");
            print_bucket(list);
            printf("\n\n\n");

        }printf("on reremplie la liste a partir des bucket\n\n\n");
        for(int j = 0; j<base;j++){
            printf(" bucket[%d] : ",j);
            print_bucket(bucket_list[j]);
            while(!is_empty(bucket_list[j])){
                printf("value : %s\n", head(bucket_list[j]));
                list = insert_tail(list, head(bucket_list[j]));
                bucket_list[j] = remove_head(bucket_list[j]);
            }
        }
        print_bucket(list);
    }
    return list;
}

void insert_bucket_list(Bucket* bucket_list, Bucket list, char position)
{
    printf("\n");
    switch(position)
    {
        case '0':
            bucket_list[0] = insert_tail(bucket_list[0], head(list));
            break;
        case '1':
            bucket_list[1] = insert_tail(bucket_list[1], head(list));
            break;
        case '2':
            bucket_list[2] = insert_tail(bucket_list[2], head(list));
            break;
        case '3':
            bucket_list[3] = insert_tail(bucket_list[3], head(list));
            break;
        case '4':
            bucket_list[4] = insert_tail(bucket_list[4], head(list));
            break;
        case '5':
            bucket_list[5] = insert_tail(bucket_list[5], head(list));
            break;
        case '6':
            bucket_list[6] = insert_tail(bucket_list[6], head(list));
            break;
        case '7':
            printf("switch");
            bucket_list[7] = insert_tail(bucket_list[7], head(list));
            printf("after insertion");
            break;
        case '8':
            bucket_list[8] = insert_tail(bucket_list[8], head(list));
            break;
        case '9':
            printf("switch");
            bucket_list[9] = insert_tail(bucket_list[9], head(list));
            printf("after insertion");
            break;
        case 'a':
            bucket_list[10] = insert_tail(bucket_list[10], head(list));
            break;
        case 'b':
            bucket_list[11] = insert_tail(bucket_list[11], head(list));
            break;
        case 'c':
            bucket_list[12] = insert_tail(bucket_list[12], head(list));
            break;
        case 'd':
            bucket_list[13] = insert_tail(bucket_list[13], head(list));
            break;
        case 'e':
            bucket_list[14] = insert_tail(bucket_list[14], head(list));
            break;
        case 'f':
            bucket_list[15] = insert_tail(bucket_list[15], head(list));
            break;
        default:
            exit(EXIT_FAILURE);
    }
}