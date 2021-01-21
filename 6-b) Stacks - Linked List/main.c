#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 4


typedef struct node{ //LINKED LIST

    int data;
    struct node *next;

}Node;

typedef struct{

    struct node *top;
    int counter;

}stack;

int IsEmpty(stack *stk);
int IsFull(stack *stk);
void Push(stack *stk, int dataToAdd);
void Pop(stack *stk);
void Peek(stack *stk);

int main()
{
    //THIS IS OUR ASSEMPTION
    stack stk;
    stk.top = NULL;
    stk.counter = 0;

    int i = 0;

    //4 TIMES PUSH TO THE STACK (0 - 1 - 2 - 3)
    for(i = 0;i<STACK_SIZE;i++){

        Push(&stk,i);

    }

    //DELETE TOP ITEM (3)
    Pop(&stk);

    //PRINT LAST TOP ITEM (2)
    Peek(&stk);


    return 0;
}

//O(1)
int IsEmpty(stack *stk)
{
    if(stk->counter == 0){

        return 1;

    }
    else{

        return 0;

    }

}

//O(1)
int IsFull(stack *stk)
{

    if(stk->counter == STACK_SIZE){

        return 1;

    }
    else{

        return 0;

    }

}

//O(1)
void Push(stack *stk, int dataToAdd)
{

    if(IsFull(stk) == 0){

        //CREATE ITEM
        Node *pItem;
        pItem = (Node *)malloc(sizeof(Node));
        if(pItem == NULL){

            printf("error");

        }

        //FILL IN
        pItem->data = dataToAdd;
        pItem->next = stk->top;

        //MAKE CONNECTIONS
        stk->top = pItem;
        stk->counter += 1;

    }
    else{

        printf("Stack is full");

    }


}

//O(1)
void Pop(stack *stk)
{

    if(IsEmpty(stk) == 0){

        Node *itemToDel;
        itemToDel = stk->top;

        stk->top = stk->top->next;
        stk->counter -= 1;
        free(itemToDel);

    }
    else{

        printf("Stack is empty\n");

    }


}

//O(1)
void Peek(stack *stk)
{

    if(IsEmpty(stk) == 0){


        printf("Top Data..:%d\n",stk->top->data);

    }
    else{

        printf("Stack is empty\n");

    }

}

