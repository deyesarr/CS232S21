#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    //TODO:copy setup func from previous task
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

void teardown(node_t *head) {
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals
   node_t *selected = head;
    // Linked List Implementation 
    while (head != NULL)
    {
        selected = head->next;
        free(head);
        head = selected;
    }
}

void add(node_t ** head, char * str, int length){
    //TODO: copy add func from task2
  node_t *currentAdd = (node_t *)malloc(sizeof(node_t));
    strcpy(currentAdd->str, str);
    currentAdd->length = length;
    currentAdd->next = *head;
    *head = currentAdd;
}
void delete_node_at(node_t ** head, int idx) {
    //TODO: implement delete a node based on index
	//deletes a node at index idx, which ranges from zero to the length of the list - 1.
   node_t * selected = *head;
      for (int i = 0; selected != NULL && i < idx; i++){ 
           selected = selected->next;
      }
  //if this node=head
    if (idx == 0){
       *head = selected->next;
        free(selected);
        return;
      }
      node_t *forward = selected->next->next;
      free(selected);
      selected->next = forward;
} 
void delete_node_key(node_t **head, char * key) {
  //TODO: implement delete a node based on key
	//given a certain key, find and delete. 
  node_t *selected = *head;
  node_t *before = NULL;

    // if this node is head node
    if (selected != NULL && strcmp(selected->str, key) == 0)
    {
        selected = selected->next;
        free(selected);
        return;
    }
    //move through nodes to find & delete key
    while (selected != NULL && strcmp(selected->str, key) != 0)
    {
        before = selected;
        selected = selected->next;
    }
    before->next = selected->next;
    free(selected);
}
void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
    delete_node_key(&head, "prof");
    delete_node_at(&head, 0);
    dump_all(head);
    teardown(head);
    return 0;
}

void dump_all(node_t * head) {
    printf("head -> ");
    node_t * cur = head;
    while(cur != NULL) {
        printf("%s ", cur->str);
	cur = cur->next;
    }
    printf("\ndone\n ");
}
