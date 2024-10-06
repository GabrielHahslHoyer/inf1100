#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*
First written without the help of any external tools then troubleshot through chatgpt. Link to conversation: https://chatgpt.com/share/67012437-1e14-8008-b277-e933be66cb71
Pre enhanced code is added as a comment underneath the active function for comparison. Added retroactively so may have missed something
*/

//defining nodes
typedef struct node {
    void *data;
    struct node *next;
}node;

//defining lists
struct list{
    node *head;
    node *tail;
    int length;
};

typedef struct list list_t;

//defining list iterator
struct list_iterator{
    node *current;
};
typedef struct list_iterator list_iterator_t;

//making an empty list
list_t *list_create(void) {
    list_t *newList = malloc(sizeof(list_t));
    if (newList == NULL) return NULL; //added by chatgpt, faisafe if malloc fails for some reason 
    newList->head = NULL;
    newList->tail = NULL;
    newList->length = 0;
    return newList;
}

//freeing up all the pointers in the list, data still exists tho, if it were to run for a while it would prolly mem leak 
//starts at the head of the list and deletes the node then goes to the next node until the list is empty
void list_destroy(list_t *list) {
    node *temp = list->head;
    while (temp != NULL) //fixed with help by chatgpt's troubleshooting, same chatlog, failsafe for empty list
    {
        node *nextNode = temp->next; 
        free(temp); 
        temp = nextNode;
    }
    free(list);
}
/*
void list_destroy(list_t *list) {
    node *temp = list->head;
    while (temp != NULL)
    {
        list->head = list->head->next; 
        free(temp); 
        node *temp = list->head;
    }
    free(list);
}
*/

//adds a new node at the start of the list. Allocates space for the node in memory, checks if the list has any members and updates head and tail accordingly
void list_addfirst(list_t *list, void *item) {
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL) return; //failsafe for failed malloc

    newNode->data = item;
    newNode->next = list->head;
    list->head = newNode;

    if (list->tail == NULL) {
        list->tail = newNode;  //updates tail if needed
    }

    list->length++;
}

/*
void list_addfirst(list_t *list, void *item) {
    node *newNode = malloc(sizeof(node));
    newNode->data = item;
    newNode->next = list->head;

    if (list->tail == NULL){
        newNode = list->tail;
    }
    else newNode = list->head;
    list->length++;
}
*/

//highly altered by chatgpt
//adds a node to the end of the list and updates the tail, also the head if needed
void list_addlast(list_t *list, void *item) {
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL) return; //failsafe if malloc fails

    newNode->data = item;
    newNode->next = NULL;
    if (list->head == list->tail){  //updates head and tail if list is empty
        list->head = newNode;
        list->tail = newNode;
    }
    else if (list->tail == NULL) {   //updates tail if empty
        list->tail = newNode;
    } else {    //updates tail if not empty
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->length++;
}

/*
void list_addlast(list_t *list, void *item) {
    if (list->head == NULL){
        list_addfirst(list, item);
    }
    else {
        node *newNode = malloc(sizeof(node));
        newNode->data = item;
        list->tail->next = newNode;
        newNode->next = NULL;
        newNode = list->tail;
        list->length++;
    }
}
*/

//mostly taken from chatgpt's troubleshooting, same chatlog as earlier, copied from chatgpt
//removes a node from the list, goes through the list until it finds the node with the given item/data and deletes it, updates the pointers of the previous and next node accordingly so that they are connected
void list_remove(list_t *list, void *item) {
    if (list->head == NULL) return;  // If the list is empty, do nothing

    node *temp = list->head;
    node *prev = NULL;

    // If the item to remove is the head
    if (temp->data == item) {
        list->head = temp->next;
        if (list->head == NULL) {
            list->tail = NULL;  // If the list is now empty, set tail to NULL
        }
        free(temp);
        list->length--;
        return;
    }

    // Traverse the list to find the item
    while (temp != NULL && temp->data != item) {
        prev = temp;
        temp = temp->next;
    }

    // If the item is not found
    if (temp == NULL) return;

    // If the item is found and it's the tail
    if (temp == list->tail) {
        list->tail = prev;
    }

    // Remove the node
    prev->next = temp->next;
    free(temp);
    list->length--;
}
   
/*
void list_remove(list_t *list, void *item) {
    node *temp = list->head;
    if (temp->data == item)
    {
        list->head = list->head->next;
        free(temp);
        list->length--;
    }
    else {
         while (temp->next->data != item)
        {
            temp = temp->next;
        }
        node *toDelete = temp->next; 
        if (temp->next->next == list->tail){
            temp->next = list->tail;
        }
        else {
            temp->next = temp->next->next;
        }
        free(toDelete);
        list->length--;
    }
}
*/

//originally a while loop, but I realised that's stupid
//checks the length of the list by, you won't belive this, returning the length of the list
int list_size(list_t *list) {
    return list->length;
    
}
/*
int list_size(list_t *list) {
    node *temp = list->head;
    int i = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
    
}
*/

//failsafes added by chatgpt
//creates an iterator and sets it to be the head of the list, returns the iterator
list_iterator_t *list_createiterator(list_t *list) {
    if (list == NULL) return NULL;  //failsafe for empty list

    list_iterator_t *count = malloc(sizeof(list_iterator_t));
    if (count == NULL) return NULL;     //failsafe for failed malloc
    count->current = list->head;
    return count;
}

/*
list_iterator_t *list_createiterator(list_t *list) {
    list_iterator_t *count = malloc(sizeof(list_iterator_t));
    count->current = list->head;
    return count;
}
    */

//makes the iterator go bye bye
void list_destroyiterator(list_iterator_t *iter) {
    free(iter);
}


//code changed with the help of chatgpt's troubleshooting, same chatlog as earlier, copied from chatgpt
//makes the iterator go to the next node in the sequence and returns the data that was in the original iterator
void *list_next(list_iterator_t *iter) {
    if (iter->current == NULL) return NULL;  // If current is NULL, we're at the end

    void *data = iter->current->data;  // Get the data from the current node
    iter->current = iter->current->next;  // Advance to the next node

    return data;  // Return the data
}

/*
void *list_next(list_iterator_t *iter) {
    iter->current = iter->current->next;
    return iter->current; 
}
*/
//should resets the iterator, also it isn't used anywhere in the code so I left it empty
void list_resetiterator(list_iterator_t *iter) {
    
}
