//implementation of linear queue: cannot re-use the empty spaces after deleting data

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 5
#define EMPTY -999
//functions
//enqueue -add a new item to the rear
//dequeue -get and remove an from front of the queue
//isEmpty -Determine whetheer the queue is empty
//isFull - determine whether the queue is full
//peek - get the element at the front of the queue without removing it

struct queue{
    int data;
    int q_arr[MAX_SIZE];
    int front;
    int rear;

};

//isFull - determine whether the queue is full
bool isFULL(struct queue q){

    if(q.rear < MAX_SIZE){
        return true;
    }
    else{
        return false;
    }

}

//isEmpty -Determine whetheer the queue is empty if front is 
bool isEmpty(struct queue q){

    if(q.front == q.rear){
        return true;
    }
    else{
        return false;
    }
}


//enqueue -add a new item to the rear
void enQueue(struct queue *q, int data){
    
    if(isFULL(*q)){
        q->q_arr[q->rear++] = data;
        printf("%d has been added to the queue\n", data);
        
    }
    else{
        printf("Queue Overflow\n");
    }
}//end of insert

//dequeue -get and remove an from front of the queue
int deQueue(struct queue *q){

    if(isEmpty(*q)){
        printf("queue is empty\n");
        return -999;
    }
    else{
        printf("removing %d from queue\n", q->q_arr[q->front]);
        return q->q_arr[q->front++];
    }
}


//peek - get the element at the front of the queue without removing it
void peek(struct queue q){
    if(isEmpty(q)){
        printf("queue is empty\n");

    }
    else{
        printf("Front of the queue is %d", q.front);
    }
    
}

void display(struct queue q)
{
    int i;
    if (q.front == q.rear)
    printf("Queue is empty \n");
    else
    {
        printf("\nQueue is : \n");
        //display the array from front to the rear
        for (i = q.front; i < q.rear; i++)
            printf("%d ", q.q_arr[i]);
        printf("\n\n");
    }
} /*End of display() */

void initQ(struct queue *q)
{
    q->front = 0;
    q->rear = 0;
}

int main(void){

    struct queue *myQ = (struct queue*)malloc(sizeof(struct queue));

    initQ(myQ);

    int choice;
    int data;

    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nWhat data you want to put in the queue?: ");
                scanf("%d", &data);
                enQueue(myQ,data);
                display(*myQ);
                break;
            case 2:
                data = deQueue(myQ);
                if(data != EMPTY)
                {
                    printf("\n%d deleted from queue\n", data);                
                    display(*myQ);
                }        
                break;
            case 3:
                display(*myQ);
                break;
            case 4:
                exit(1);
            default:
                printf("Wrong choice \n");
        } /*End of switch*/
    } /*End of while*/
    return 0;

}