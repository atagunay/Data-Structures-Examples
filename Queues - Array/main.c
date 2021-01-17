#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

typedef struct TagQueue{

    int front;
    int rare;
    int counter;
    int data[QUEUE_SIZE];

}queue;

int IsEmpty(queue *pQueue);
int IsFull(queue *pQueue);
void Push(queue *pQueue, int dataToAdd);
void Pop(queue *pQueue);
void Peek(queue *pQueue);

int main()
{
    queue Queue;

    //THESE ARE QUEUE ASSEMPTIONS
    Queue.front = 0;
    Queue.counter = 0;
    Queue.rare = -1;


    int i = 0;

    //ADD 10 ITEM TO THE QUEUE(0-1-2-3-4-5-6-7-8-9-10)
    for(i = 0;i<QUEUE_SIZE;i++){

        Push(&Queue,i);


    }

    //DELETE FIRST ITEM, (0)
    Pop(&Queue);

    //PRINT FIRST ITEM, (1)
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
    if(pQueue->counter == QUEUE_SIZE){

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

        pQueue->rare++;
        pQueue->counter++;

        if(pQueue->rare == QUEUE_SIZE){

            pQueue->rare = 0;
        }

        pQueue->data[pQueue->rare] = dataToAdd;


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


        pQueue->front++;
        pQueue->counter--;

        if(pQueue->front == QUEUE_SIZE){

            pQueue->front = 0;

        }


    }
    else{

        printf("List is EMPTY\n");

    }


}

//O(1)
//IT IS A CONSTANT TIME JOB
//WE PROCESS ONLY ONE TIME
//WE CAN LOOK TOP ITEM AT THE QUEUE WITH ONE STEP
void Peek(queue *pQueue)
{

    printf("Data..:%d\n",pQueue->data[pQueue->front]);

}
