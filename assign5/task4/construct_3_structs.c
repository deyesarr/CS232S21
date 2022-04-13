#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    node_t * head ;
    //TODO:head declared for you
    //Allocate three more pointers
    //head for the first Node, and temporary pointers node1, node2 and node3
    //Allocate three node pointees and store references to them in the three pointers
    node_t * firstNode = (struct snode*)malloc(sizeof(node_t));
    node_t * secondNode = (struct snode*)malloc(sizeof(node_t));
    node_t * thirdNode = (struct snode*)malloc(sizeof(node_t));
    //Dereference each pointer to store the appropriate number and string into the length and str fields in its pointee.
    //Dereference each pointer to access the .next field in its pointee, 
    //and use pointer assignment to set the .next field to point to the appropriate Node. 

  strcpy(firstNode->str, "hello");
    firstNode->length = 5;//string length
    firstNode->next = secondNode;//pointer to next node

    strcpy(secondNode->str, "there");
    secondNode->length = 5;//string length
    secondNode->next = thirdNode;//pointer to next node

    strcpy(thirdNode->str, "prof");
    thirdNode->length = 4;//string length
    thirdNode->next = NULL;//pointer to nonexistent next node

    head = firstNode;// initialize head node
  
   return head;
}

void teardown(/*what parameter?*/) {
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals
   node_t *cur = head;
    while (head != NULL)
    {
        // Linked List implementation
        cur = head->next;
        free(head);
        head = cur;
    }
}

void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    dump_all(head);
    teardown(head);
    return 0;
}

void dump_all(node_t * head) {
    printf("head -> ");
    node_t * selected = head;
    while(selected != NULL) {
        printf("%s ", selected->str);
	      selected = selected->next;
    }
    printf("\nComplete\n ");
}
