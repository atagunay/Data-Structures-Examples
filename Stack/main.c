#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 4

typedef struct{

    int data[STACK_SIZE];
    int top; //WE KEEP INDEX OF TOP ITEM

}stack;

void push(stack *stk, int dataToAdd); //ADD
void reset(stack *stk); //DELETE ALL STACK
void printStack(stack *stk); // PRINT
void pop(stack *stk); //DELETE TOP ITEM
void peek(stack *stk); //LOOK TOP ITEM

int main()
{
   //THIS IS OUR STATICK ASSUMPTION
    stack stk;
    stk.top = -1;
    int selection = 0;

    while(selection != 99){

        printf("1-) PUSH    (ADD ITEM)\n");
        printf("2-) POP     (DELETE TOP ITEM)\n");
        printf("3-) RESET   (DELETE ALL STACK)\n");
        printf("4-) PRINT   (PRINT ALL STACK)\n");
        printf("5-) PEEK    (LOOK TOP ITEM STACK)\n");
        printf("-->");
        scanf("%d",&selection);

        if(selection == 1){

            int number;

            printf("enter data to add..:");
            scanf("%d",&number);

            push(&stk,number);

        }
        else if(selection == 2){

            pop(&stk);


        }
        else if(selection == 3){

            reset(&stk);

        }
        else if(selection == 4){

            printStack(&stk);

        }
        else if(selection == 5){

            peek(&stk);

        }
    }



    return 0;


}

//O(1)
//IT IS A CONSTANT TIME JOB
//WE PROCESS ONLY ONE TIME
//WE ADD ITEM TO THE STACK WITH ONE STEP
void push(stack *stk, int dataToAdd)
{
    //IF LIST IS FULL
    if(stk->top == STACK_SIZE - 1){

        printf("Stack is full\n");

    }
    else{

        stk->top += 1;
        stk->data[stk->top] = dataToAdd;
    }


}

//O(N)
//WE HAVE A FOR LOOP
//THIS IS FOR PRINTING ALL ITEM ON BY ONE
//WE MUST TRAVEL THE LIST
void printStack(stack *stk)
{
    int i = 0;

    for(i = 0;i<STACK_SIZE;i++){

        printf("%d.Data..:%d\n",i+1,stk->data[i]);

    }

}

//O(1)
//IT IS A CONSTANT TIME JOB
//WE PROCESS ONLY ONE TIME
//WE DELETE ALL ITEM FROM THE STACK WITH ONE STEP
void reset(stack *stk)
{

    stk->top = -1;


}

//O(1)
//IT IS A CONSTANT TIME JOB
//WE PROCESS ONLY ONE TIME
//WE DELETE ITEM FROM THE STACK WITH ONE STEP
void pop(stack *stk)
{
    if(stk->top == -1){

        printf("Stack is empty\n");

    }
    else{

        stk->top -= 1;

    }

}

//O(1)
//IT IS A CONSTANT TIME JOB
//WE PROCESS ONLY ONE TIME
//WE CAN LOOK TOP ITEM AT THE STACK WITH ONE STEP
void peek(stack *stk)
{
    if(stk->top == -1){

        printf("Stack is empty\n");

    }
    else{

        printf("%d\n",stk->data[stk->top]);

    }


}
