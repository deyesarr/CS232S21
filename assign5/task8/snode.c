#include <stdio.h>
#include "snode.h"
#include <string.h>
#include <stdlib.h>

struct snode *snode_create(void *s) 
{
 //TODO: implement snode_create, change the prototype to
 //match with header file
 //return node;
    struct snode *node;
    node = malloc(sizeof(struct snode));
    strcpy(node->str, s);
    node->next = NULL;
    return node;
}
void snode_destroy(struct snode * s) 
{

 //TODO: implement snode_destroy
    s=NULL;
    free(s->str);//free memory
    free(s);//free structure
};
 
