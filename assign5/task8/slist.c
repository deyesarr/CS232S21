struct slist {
  struct snode *front; // front node
  struct snode *back;  // back node
};

/**
 * Allocates new slist dynamically.
 * 
 * @return pointer to the list
 */
struct slist *slist_create();
{
  struct slist *new_slist = malloc(sizeof(struct snode));

	new_slist->front = NULL;
	new_slist->back = NULL;

	return new_slist;
}
/** 
 * Inserts new node in slist after the last node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
struct snode* slist_add_back(struct slist *l, void *str);{
  struct snode *node = malloc(sizeof(struct snode));
    node = snode_create(str); 
    if (NULL == l->front) {
        l->back = node;
        l->front = node;
        l->counter = 1;
    }
    else {
        l->back->next = node;
        l->back = node;
        l->counter++;
    }
    return node;
    free(node);
  }

/** 
 * Inserts new node in slist before the first node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
struct snode* slist_add_front(struct slist *l, void *str);{
struct snode *node = malloc(sizeof(struct snode));
    node = snode_create(str);
    if (NULL == l->front) {
        l->back = node;
        l->front = node;
    }
    else {
        node->next = l->front;
        l->front = node;
    }
    return node;
    free(node);
  }
/**
 * Returns the first snode with the given string.
 *  
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 * @return struct snode* or NULL if no match
 */
struct snode* slist_find(struct slist *l, void *str);{
struct snode *itr = l->front;
	while (itr != NULL)
	{
		if (strcmp(itr->str, str) == 0)
		{
			return itr;
		}
		itr = itr->next;
	}
	return itr;
	free(itr);
  }
/**
 * Deallocate a list and all snodes
 *
 * @param l pointer to the list
 */
void slist_destroy(struct slist *l);{
  struct snode *selected, *afterCurrent;
   selected = l->front;
   afterCurrent = selected->next;
   do{
      snode_destroy(selected);
      selected = afterCurrent;
      afterCurrent = afterCurrent->next;
   }while (afterCurrent != NULL);
   snode_destroy(selected);
   snode_destroy(afterCurrent);
   free(l);
  }

/**
 * Traverse the list and print the content of each node.
 *
 * @param l pointer to the list (non-NULL)
 */
void slist_traverse(struct slist *l);{
struct snode *current;
   current = l->front;
   while(current != NULL){
      printf("%s\n", current->str);
      current = current->next;
   }
  free(current);
  }
/**
 * Returns the number of elements in the list (nodes).
 *
 * @param l pointer to the list (non-NULL)
 */
  
uint32_t slist_length(struct slist *l);
{
int len;
	struct snode *current = l->front;

	while (NULL != current)
	{
		++len;
		current = current->next;
	}
	return len;
  }
/**
 * Deletes the first snode with the given string.
 *  
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 */
void slist_delete(struct slist *l, void *str);
{
struct snode *selected, *before;
   selected = l->front;
   before = l->front;
   do{
      if(strcmp(selected->str, str)){
          if(selected == l->front){
             l->front = selected->next;
          } else {
             before->next = selected->next;
             snode_destroy(selected);
          }
          break;
      }
      before = selected;
      selected = before->next;
   }while(selected != NULL);
  prev->next = temp->next;

  return temp;
	free(temp);
  }
#endif /* _slist_H_ */
