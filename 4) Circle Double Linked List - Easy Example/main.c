#include <stdio.h>
#include <stdlib.h>

typedef struct tagCircleDoublyLinkedList{

    int data;
    struct tagCircleDoublyLinkedList *prev;
    struct tagCircleDoublyLinkedList *next;

}DLLI;

DLLI *addhead(DLLI *head, int key);
DLLI *addlast(DLLI *head, int key);
DLLI *deleteLastItemEffiency(DLLI *head);
DLLI *double_linked_remove(DLLI* head, int dataToDel);
void printList(DLLI *first);

int main()
{
    int i = 0;

    DLLI *head;
    head = NULL;

    for(i = 0;i<10;i++){

        head = addlast(head, i);

    }

    head = deleteLastItemEffiency(head);

    printList(head);


}

//O(1)
//WE ADD ITEM TO HEAD
//SO WE DONT HAVE TO LOOK ALL ITEMS ONE BY ONE
//OUR FUNCTION WORKS ONLY ONE TIME AND THEN FINIS THE TASK
//SO THIS IS CONSTANT TIME
DLLI *addhead(DLLI *head, int key)
{

    //IF LIST IS EMPTY
    if(head == NULL) {

        //CREATE ITEM
        head = (DLLI *)malloc(sizeof(DLLI));
        if(head == NULL){

            printf("error");
        }

        //FILL ITEM
        head -> data = key;

        //LOCATED
        head -> next = head;
        head -> prev = head;

    }
    else {//IF LIST HAS AT LEAST ONE ITEM

        //CREATE ITEM
        DLLI *pNewItem = (DLLI *)malloc(sizeof(DLLI));
        if(pNewItem == NULL){

            printf("error");

        }

        //FILL
        pNewItem -> data = key;

        //LOCATED
        head->prev->next=pNewItem;
        pNewItem->next=head;
        pNewItem->prev=head->prev;
        head->prev=pNewItem;

        //NEW HEAD
        head = pNewItem;
    }

    return head;
}

//O(1)
//WE ADD ITEM TO LAST IN THE CIRCLE LIST
//AND WE DONT HAVE TO LOOK ALL ITEMS ONE BY ONE
//BECAUSE WE KNOW THE ADRESS OF LAST ITEM
//OUR FUNCTION WORKS ONLY ONE TIME AND THEN FINIS THE TASK
//SO THIS IS CONSTANT TIME
DLLI *addlast(DLLI *head, int key)
{

    //IF LIST IS EMPTY
    if(head == NULL) {

        //CREATE ITEM
        head = (DLLI *)malloc(sizeof(DLLI));
        if(head == NULL){

            printf("error");
        }

        //FILL ITEM
        head -> data = key;

        //LOCATED
        head -> next = head;
        head -> prev = head;

    }
    else {//IF LIST HAS AT LEAST ONE ITEM

        //CREATE ITEM
        DLLI *pNewItem = (DLLI *)malloc(sizeof(DLLI));
        if(pNewItem == NULL){

            printf("error");

        }

        //FILL
        pNewItem -> data = key;

        //LOCATED
        head->prev->next=pNewItem;
        pNewItem->next=head;
        pNewItem->prev=head->prev;
        head->prev=pNewItem;


    }

    return head;
}

//O(N)
//WE PRINT LIST ONE BY ONE
//SO WE TRAVEL ALL LIST
void printList(DLLI *head)
{
    DLLI *temp = head;

    // If linked list is not empty
    if (head != NULL)
    {
        // Keep printing nodes till we reach the first node again
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while (temp != head);
    }
}

//O(N)
//WE HAVE TWO CASE, WE SHOULD THINK WORST CASE
//OUR WORST CASE IS IN CASE2
//IN CASE 2, IF ITEM THAT WE NEED TO DELETE AT LAST INDEX
//WE MUST TRAVEL ALL LIST
//AND THE WE DELETE
DLLI* double_linked_remove(DLLI* head, int dataToDel)
{
    // EMPTY LIST CHECK
    if (NULL != head) {
        DLLI* temp = head;

        while(NULL != temp && temp->data != dataToDel)
            temp = temp->next;

        // NOT FOUND - Data is NOT in the list
        if (NULL != temp) {
            // ITEM FOUND - Remove it!
            // 1- Set the previous item's next value
            if (NULL != temp->prev)// If temp is NOT the first item!
                temp->prev->next = temp->next;

            // 2- Set the next item's previous value
            if (NULL != temp->next) // If it is NOT the last item
                temp->next->prev = temp->prev;

            if (head == temp)
                head = temp->next;

            free(temp);
        }
    }
    return head;
}

//O(1)
//NORMALLY WE SHOULD FIND LAST ITEM BUT =>
//WE HAVE A CIRCLE LIST SO FIRST ITEM LINKED WITH LAST ITEM
//WHEN WE WANT TO DELETE LAST ITEM, WE HAVE A CONSTANT JOB
//WE CAN ACSESS LAST ITEM ONLY ONE PROCESS
//SO IT IS ONLY 1 PROCESS FOR BIG O
DLLI *deleteLastItemEffiency(DLLI *head)
{

    DLLI *deleteItem;
    deleteItem = head->prev;

    head->prev->prev->next = head;
    head->prev = head->prev->prev;

    free(deleteItem);


    return head;
}
