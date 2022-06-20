
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

    struct node *temp = (struct node *)malloc(struct node);
    temp->data = data;
    temp->next = NULL;

    if(head == NULL){
        temp->prev = NULL;
        head = temp;
    }
    else{
        struct node *t = head; //traversal

        while(t->next != NULL){
            t =  t->next;
        }

        temp->prev = t;
        t->next = temp;
    }

    return head;
}

struct node *sorted_insert(struct node *head, int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp ->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if(head == NULL){
       head = temp;
    }
    else if(head->data >= data){
        temp->next =  head;
        temp->next->prev = temp;
        head = temp;
    }
    else{//traversal phase

        struct node *t = head;

        while(t->next != NULL && t->next->data < data){
            t = t->next;
        }

        temp->next = t->next;

        if(t->next != NULL){
            temp->next->prev = temp;
        }

        t->next = temp;
        temp->prev = t;
    }

    return head;
}

int main(void){

    struct node *head = NULL;
}