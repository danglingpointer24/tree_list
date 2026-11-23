#include "tree_list.h"
#include <stdio.h>
#include <string.h>

int main(void) 
{
    struct Tree *x=Tree_new();
    
    if(!x) {
        fprintf(stderr, "There is no tree\n"); 
        return 1;
    }
    
    char key [50];
    int value, input_count, j; 
    int i=0;
    
    while(1) 
    {
        printf("Enter the key and the value of node %d (or exit 0 to quit): \n", i+1);
        input_count = scanf("%49s %d", key, &value);
        
        if(input_count!=2)
        {
            printf("Invalid input.\n");
            while((j=getchar())!='\n' && j!=EOF) 
                ;
            continue;
        }
        
        if(!strcmp(key,"exit")) break;
        x->put(x, key, value);
        ++i;
    }
    
    printf("\nYour tree @%p count=%d\n", (void*)x, x->size(x));
    printf("\nPre-order traversal:\n");
    x->pre_order_dump(x);  
    printf("\nIn-order traversal:\n");
    x->in_order_dump(x); 
    printf("\nIterating:\n");
    struct TreeIter* iter=x->iter(x);
    struct TreeEntry* cur;
    while(1){
        cur=iter->next(iter);
        if(!cur) break;
        printf("%s = %d\n", cur->key, cur->value);}
    
    iter->iter_del(iter);
    x->del(x);
    return 0;
}  


