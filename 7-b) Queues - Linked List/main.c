#include <stdio.h>
#include <stdlib.h>

#define QUEUSE_SIZE 10

typedef struct TagNode{

    int data;
    struct TagNode *next;

}node;

typedef struct TagQueue{

    int counter;
    struct TagNode *front;
    struct TagNode *rare;


}queue;

int IsEmpty(queue *pQueue);
int IsFull(queue *pQueue);
void Push(queue *pQueue, int dataToAdd);
void Pop(queue *pQueue);
void Peek(queue *pQueue);

int main()
{
    //THIS ARE QUEUE ASSEMPTIONS
    queue Queue;
    Queue.counter = 0;
    Queue.front = NULL;
    Queue.rare = NULL;

    int i = 0;

    //ADD 10 ITEMS TO THE QUEUE
    for(i = 0;i<QUEUSE_SIZE;i++){

        Push(&Queue,i);

    }

     //DELETE FIRS ITEM FROM THE QUEUE(1)
     Pop(&Queue);

     //DELETE FIRS ITEM FROM THE QUEUE(2)
     Pop(&Queue);

     //PRINT FIRST ITEM OF QUEUE(2)
     Peek(&Queue);


    return 0;
}

//O(1)
//IT IS A CONSTANT TIME JOB
//WE PROCESS ONLY ONE TIME
//WE CAN CHECK IF QUEUE IS EMPTY WITH ONE STEP
int IsEmpty(queue *pQueue)
{
    if(pQueue->counter == 0){

        return 1;
    }
    else{

        return 0;
    }
}

//O(1)
//IT IS A CONSTANT TIME JOB
//WE PROCESS ONLY ONE TIME
//WE CAN CHECK IF QUEUE IS FULL WITH ONE STEP
int IsFull(queue *pQueue)
{
    if(pQueue->counter == QUEUSE_SIZE){

        return 1;
    }
    else{

        return 0;
    }
}

//O(1)
//IT IS A CONSTANT TIME JOB
//WE PROCESS ONLY ONE TIME
//WE ADD ITEM TO THE QUEUE WITH ONE STEP
void Push(queue *pQueue, int dataToAdd)
{
    if(IsFull(pQueue) == 0){

        //CREATE ITEM
        node *pItem;
        pItem = (node *)malloc(sizeof(node));
        if(pItem == NULL){

            printf("error");
        }

        //FILL IN
        pItem->data = dataToAdd;
        pItem->next = NULL;

         //SET LINKS
        if(IsEmpty(pQueue) == 1){//IF LIST IS EMPTY FRONT AND RARE MUST POINT SAME ITEM

            pQueue->front = pItem;
            pQueue->rare = pItem;
        }
        else{

            pQueue->rare->next = pItem;
            pQueue->rare = pItem;

        }

        //INCREASE COUNTER
        pQueue->counter++;

    }
    else{

        printf("Queue is FULL\n");
    }
}

//O(1)
//IT IS A CONSTANT TIME JOB
//WE PROCESS ONLY ONE TIME
//WE DELETE ITEM FROM THE QUEUE WITH ONE STEP
void Pop(queue *pQueue)
{
    if(IsEmpty(pQueue) == 0){

        //CREATE DELETE ITEM
        node *deleteItem;
        deleteItem = pQueue->front;

        //SET LINKS
        pQueue->front = pQueue->front->next;
        free(deleteItem);

        //DECREASE COUNTER
        pQueue->counter--;


    }
    else{

        printf("Queue is EMPTY\n");
    }
}

//O(1)
//IT IS A CONSTANT TIME JOB
//WE PROCESS ONLY ONE TIME
//WE CAN LOOK TOP ITEM OF THE QUEUE  WITH ONE STEP
void Peek(queue *pQueue)
{
    printf("Data..:%d\n",pQueue->front->data);
}
