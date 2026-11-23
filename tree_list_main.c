#include "tree_list.h"
#include <stdio.h>

int main(void)
{
    struct Tree *x=Tree_new();
    
    if(!x) {
        fprintf(stderr, "There is no tree\n"); 
        return 1;
    }
    
    x->put(x,"Nick_Cave_and_the_Bad_Seeds",22);
    x->put(x,"Thom_Yorke",10);
    x->put(x,"Cranberries",11);
    x->put(x,"XX",2);
    x->put(x,"Muse",4);
    x->put(x,"Atoms_for_Peace",15);
    x->put(x,"Talking_Heads",13);
    x->put(x,"Iggy_Pop",8);
    x->put(x,"R.E.M.",6);
    x->put(x,"Pixies",6);
    x->put(x,"Dirty_Three",11);
    x->put(x,"Radiohead",9);
    x->put(x,"Joy_Division",12);
    x->put(x,"Smiths",6);
    x->put(x,"Keane",5);
    x->put(x,"Nick_Cave_and_the_Bad_Seeds",27);   /* updating a value */
    
    printf("\nObject Tree @%p count=%d\n", (void*)x, x->size(x));
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
    
    printf("\nDemonstrating the get method: \n");
    int y = x->get(x,"XX");
    printf((y==-1) ? "there is no XX in the tree so get returns default %d\n" : "XX is in the tree and get returns its value %d\n", y);
    y=x->get(x,"Crystal_Castles");
    printf((y==-1) ? "there is no Crystal_Castles in the tree so get returns default %d\n" : "Crystal_Castles is in the tree and get returns its value %d\n", y);
    
    iter->iter_del(iter);
    x->del(x);
    
    return 0;
}  
