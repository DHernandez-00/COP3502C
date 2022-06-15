
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev; //this will allow rear traversal
    struct node *next; //this will allow forward traversal
}

struct node *insert_front(struct node *head, int data){

    //make a new node to hold the information
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->prev = NULL;
    //temp->next = NULL;

    //if head is empty temp is the new head
    temp->next = head;

    if(head != NULL){
        head->prev = temp;
    }
    head = temp;

    return head;
}

struct node *insert_rear(struct node *head, int data){
    
}

int main(void){

    struct node *head = NULL;
}