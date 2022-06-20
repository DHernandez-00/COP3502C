#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define INIT_SIZE 6
#define EMPTY -999

struct queue{
    int front;
    int *elements;
    int size;
    int noe;
};

void init(struct queue *q){

    q->front = 0;
    q->elements = (int*)malloc(sizeof(int)*INIT_SIZE);
    q->size = INIT_SIZE;
    q->noe = 0;
}

bool isFULL(struct queue q){

    if(q.noe == q.size){
        return true;
    }
    else{
        return false;
    }
}

void enqueue(struct queue *q, int data){

    //check if our que is not full
    if(!isFULL(*q)){
        q->elements[(q->front + q->noe)% q->size] = data;
        q->noe++;
    }
    else{ //if our queue is full lets increase our queue size using realloc
        int i;
        q->elements = realloc(q->elements, (q->size)* sizeof(int) * 2);
        
        for(i = 0; i <= q->front - 1; i++){

            q->elements[i + q->size] = q->elements[i];
        }

        q->elements[i + q->size] = data;

        (q->size) *= 2;
        (q->noe)++;

    }
}

bool isEMPTY(struct queue q){
    if(q.noe == 0){
        return true;
    }
    else{
        return false;
    }
}
int dequeu(struct queue *q){

    int retval;

    //check if the queue is empty
    if(isEMPTY(*q)){
        printf("Queue is empty nothing to deque");
        return EMPTY;
    }
    else{

        retval = q->elements[q->front];

        //move front
        q->front = (q->front + 1) % q->size;

        q->noe--;

        return retval;
        
    }
}

void display(struct queue q){

    if(isEMPTY){
        printf("queue is empty!");
    }
    else{
        printf("contents of the queue : ");

        if(q.front + q.noe < q.size){

            for(int i =  q.front; i < q.front + q.noe; i++){
                printf("%d ",q.elements[i]);
            }
        }
        else{

            for(int i = q.front ; i < q.size ;i++){
                printf("%d ",q.elements[i]);
            }
            for(int i = 0; i < (q.front + q.noe)%q.size; i++){
                printf("%d ",q.elements[i]);
            }
        }
    }
}
int main(void)
{
    //allocate space for initial Q
    struct queue *myQ = (struct queue*)malloc(sizeof(struct queue));
    int choice;
    int data;

    //initialize our values for our Q

    init(myQ);

    while (1)
    {
        printf("\n1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3. Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("\nWhat data you want to put in the queue?: ");
                scanf("%d", &data);
                enqueue(MyQueuePtr, data);
                displayQueue(MyQueuePtr);
                break;
            case 2:
                data = dequeue(MyQueuePtr);
                if(data!=EMPTY)
                    printf("\n%d deleted from queue\n", data);
                displayQueue(MyQueuePtr);
                break;
            case 3:
                displayQueue(MyQueuePtr);
                break;
            case 4:
                exit(1);
            default:
                printf("Wrong choice \n");
        } /*End of switch*/
    } /*End of while*/
    return 0;


}