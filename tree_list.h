#ifndef TREE_LIST_H
#define TREE_LIST_H

struct TreeIter;

struct TreeEntry
{
    char *key;
    int value;
    struct TreeEntry *__left;
    struct TreeEntry *__right;
    struct TreeEntry *__next;  /* for linked list */
};

struct Tree
{
    struct TreeEntry *__root;
    struct TreeEntry *__head;  /* for linked list */
    int __count;

    void (*put)(struct Tree *self, char *key, int value);
    int (*get)(struct Tree *self, char *key);
    int (*size)(struct Tree *self);
    void (*pre_order_dump)(struct Tree *self);               
    void (*in_order_dump)(struct Tree *self);        
    struct TreeIter* (*iter)(struct Tree *self);
    void (*del)(struct Tree *self);             
};

struct TreeIter
{
    struct TreeEntry *__current;
    struct TreeEntry* (*next)(struct TreeIter *self);
    void (*iter_del)(struct TreeIter *self);     
};

/* methods for struct Tree */
void __Tree_put(struct Tree *self, char *key, int value);
int __Tree_get(struct Tree *self, char *key);
int __Tree_size(struct Tree *self);
void __Tree_pre_order_dump(struct Tree *self);
void __Tree_dump_tree(struct TreeEntry *cur, int depth);
void __Tree_in_order_dump(struct Tree *self);                    
void __Tree_dump_tree_sorted(struct TreeEntry *cur);           
void __Tree_del(struct Tree *self); 

/* methods for struct TreeIter */
struct TreeEntry* __TreeIter_next(struct TreeIter *self);
void __TreeIter_iter_del(struct TreeIter *self);              

struct Tree *Tree_new();                               /* tree constructor */

struct TreeIter* __Tree_iter(struct Tree *self);       /* tree_iter constructor */

  
#endif