#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 6

struct stack{
    int top;
    int stack_array[MAX_SIZE];
};

bool isFull(struct stack mystack){

    if(mystack.top >= MAX_SIZE -1){
        return true;
    }
    else{
        return false;
    }
}

void push(struct stack *myStack, int data){

    //check if we can push onto the stack
    if(isFull(*myStack)){
        printf("stack overflow\n");
    }
    else{ //if we can push onto the stack increment first stack starts at -1
        myStack->stack_array[myStack->top + 1] = data;
        (myStack->top)++;
        printf("inserted");
    }

}
bool isEmpty(struct stack mystack){
    return mystack.top == -1;
}
int pop(struct stack *myStack){

    //check if we can pop from the stack
    if(isEmpty(*myStack)){
        printf("stack underflow\n");
        return -999;
    }
    else{ 
        return myStack->stack_array[myStack->top--];
    }
}

void init(struct stack *myStack){
    myStack->top = -1;
}

int top(struct stack *myStack){

    if(isEmpty(*myStack)){
        return -999;
    }
    else{
        return myStack->stack_array[myStack->top];
    }
}

void display(struct stack myStack){
    printf("Printing the current stack\n");

    for(int i = 0; i <= myStack.top ; i++){
        printf("%d ", myStack.stack_array[i]);
    }
}

int main(void){

    struct stack *stack1 = (struct stack*)malloc(sizeof(struct stack));
    struct stack *stack2 = (struct stack*)malloc(sizeof(struct stack));

    init(stack1);
    init(stack2);

    int ele;
    int ch;
    while(1)
    {
        printf("\nMenu:\n 1: Stack 1 push\n 2: Stack 2 Push\n 3: Stack 1 Pop\n 4: Stack 2 Pop\n 5: Stack 1 display\n 6: Stack 2 Display\n 7: Exit\nEnter your choice: ");
        scanf("%d",&ch);
        if(ch==7)
        {
            printf("<<EXIT>>");
            break;
        }
        else if (ch==1)
        {
            printf("Enter an element to PUSH in the stack1: ");
            scanf("%d",&ele);
            push(stack1, ele);
            display(*stack1);
        }
        else if (ch==2)
        {
            printf("Enter an element to PUSH in the stack2: ");
            scanf("%d",&ele);
            push(stack2, ele);
            display(*stack2);
        }
        else if (ch==3)
        {
            ele = pop(stack1);
            if(ele!=0 )
            {
                printf(" ITEM POPPED from Stack 1: %d ",ele);
                display(*stack1);
            }
        }
        else if (ch==4)
        {
            ele = pop(stack2);
            if(ele!=0 )
            {
                printf(" ITEM POPPED from Stack 2: %d ",ele);
                display(*stack2);
            }
        }
        else if(ch==5)
        {
            display(*stack1);
        }
        else if(ch==6)
        {
            display(*stack2);
        }
    }
    return 0;

}

