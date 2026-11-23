#include "tree_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tree *Tree_new()
{
  struct Tree *p=(struct Tree *)malloc(sizeof(*p));
  if(!p) return NULL;    
  p->__root=NULL;
  p->__count=0;
  p->__head=NULL;
  p->put=&__Tree_put;
  p->get=&__Tree_get;
  p->size=&__Tree_size;
  p->pre_order_dump=&__Tree_pre_order_dump;
  p->in_order_dump=&__Tree_in_order_dump;    
  p->iter=&__Tree_iter;
  p->del=&__Tree_del;                  
  return p;
}

void __Tree_del(struct Tree *self) 
{      
    struct TreeEntry *cur, *next;
    cur=self->__head;
    while(cur){
        next=cur->__next;           
        free(cur->key);
        free(cur);
        cur=next;
              }
    free(self);                 
}

struct TreeIter* __Tree_iter(struct Tree *self)
{
   struct TreeIter* iter=(struct TreeIter*)malloc(sizeof(*iter));
    iter->__current=self->__head;
    iter->next=&__TreeIter_next;
    iter->iter_del=&__TreeIter_iter_del;    
    return iter;
}

struct TreeEntry* __TreeIter_next(struct TreeIter *self)
{
    struct TreeEntry* retval=self->__current;
    if(!retval) return NULL;
    self->__current=self->__current->__next;
    return retval;
}

void __TreeIter_iter_del(struct TreeIter *self)
{                
    free(self); 
}     

int __Tree_size(struct Tree *self)
{
    return self->__count;
}

int __Tree_get(struct Tree *self, char *key)
{
struct TreeEntry *cur=self->__root;
int cmp;
while(cur){
cmp=strcmp(cur->key,key);
if (!cmp) return cur->value;
else if (cmp>0) cur=cur->__left;
else cur=cur->__right;}
return -1;
}


void __Tree_put(struct Tree *self, char *key, int value)
{   
struct TreeEntry *cur=self->__root, *left=NULL, *right=NULL;
int cmp;
while(cur){
cmp=strcmp(cur->key,key);
if (!cmp) {cur->value=value;
           return;}
if (cmp>0) {
    right=cur;
    cur=cur->__left;}
else {
    left=cur;
    cur=cur->__right;} }
   
char *save=(char *)malloc(strlen(key)+1);

if(!save) {
    fprintf(stderr, "Allocation failed for key\n");
    return;
}    
    
strcpy(save,key);
struct TreeEntry *node=(struct TreeEntry *)malloc(sizeof(*node));
    
if(!node) {
   fprintf(stderr, "Allocation failed for node\n");
   free(save);
   return;
}    
    
node->key=save;
node->value=value;
node->__left=NULL;
node->__right=NULL;
node->__next=NULL;
self->__count++;
    
if(!self->__root) {self->__root=node;     /* insert into tree */
                   self->__head=node;     /* insert into linked list */
                   return;}         

if(left) {node->__next=right;                                                            /* insert into linked list */
           left->__next=node;}                                                           /* insert into linked list */
else if(!left) {node->__next=self->__head;                                               /* insert into linked list */
           self->__head=node;}                                                           /* insert into linked list */

if(right && !right->__left) right->__left=node;        /* insert into tree */
else if(left && !left->__right) left->__right=node;    /* insert into tree */    
}

void __Tree_pre_order_dump(struct Tree *self)
{
     __Tree_dump_tree(self->__root,0);
}

void __Tree_dump_tree(struct TreeEntry *cur, int depth)
{
if(!cur) return;

for(int i=0;i<depth;i++) printf("| ");
printf("%s = %d\n", cur->key, cur->value);
if(cur->__left) __Tree_dump_tree(cur->__left,depth+1);
if(cur->__right) __Tree_dump_tree(cur->__right,depth+1);
return;
}

void __Tree_in_order_dump(struct Tree *self)
{                   
     __Tree_dump_tree_sorted(self->__root);
}

void __Tree_dump_tree_sorted(struct TreeEntry *cur)
{         
if(!cur) return;
    
if(cur->__left) __Tree_dump_tree_sorted(cur->__left);
printf("%s = %d\n", cur->key, cur->value);
if(cur->__right) __Tree_dump_tree_sorted(cur->__right);
return;
}