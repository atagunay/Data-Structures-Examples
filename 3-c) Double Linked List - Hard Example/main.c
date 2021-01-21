#include <stdio.h>
#include <stdlib.h>

typedef struct tagStudent{

    int number;
    char *name;


}Student;

typedef struct tagDoublyLinkedList {

    struct tagStudent *data;
    struct tagDoublyLinkedList* prev;
    struct tagDoublyLinkedList* next;

}DLLI;


DLLI *addItemToHead(DLLI *head, int dataToAdd);
DLLI *addItemToEnd(DLLI *head, int dataToAdd);
DLLI* double_linked_remove(DLLI *head, int key);
void printList(DLLI *head);
void printListRec(DLLI *head);

int main()
{
    //IMPORTANT RULE:
    //IF NEXT OR PREV WILL POINT ANYTHING(FOR EX: LAST ITEM OR FIRS ITEM)
    //YOU MUST FILL PREV OR NEXT WITH !--NULL--!

    int choice = 0;

    DLLI *head;
    head = NULL;

    while(choice != 99){

        printf("1-> ADD ITEM TO HEAD\n");
        printf("2-> ADD ITEM TO END\n");
        printf("3-> PRINT ALL LIST\n");
        printf("4-> PRINT ALL LIST RECURSIVE\n");
        printf("5-> DELETE ITEM BY NUMBER\n");
        printf("->");
        scanf("%d",&choice);

        if(choice == 1){

            int number;
            printf("enter number..:");
            scanf("%d",&number);

            head = addItemToHead(head, number);

        }
        else if(choice == 2){

            int number;
            printf("enter number..:");
            scanf("%d",&number);

            head = addItemToEnd(head, number);


        }
        else if(choice == 3){

            printList(head);

        }
        else if(choice == 4){

            printListRec(head);

        }
        else if(choice == 5){

            int number;
            printf("enter number..:");
            scanf("%d",&number);

            head = double_linked_remove(head,number);

        }
    }

    return 0;
}

//O(1)
//WE ADD ITEM TO HEAD
//SO WE DONT HAVE TO LOOK ALL ITEMS ONE BY ONE
//OUR FUNCTION WORKS ONLY ONE TIME AND THEN FINIS THE TASK
DLLI *addItemToHead(DLLI *head, int dataToAdd)
{
    //CREATE ITEM
    DLLI *pNewItem;

    pNewItem = (DLLI *)malloc(sizeof(DLLI));
    if(pNewItem == NULL){

        printf("error");

    }

    pNewItem->data = (Student *)malloc(sizeof(Student));
    if(pNewItem->data == NULL){

        printf("error");

    }

    pNewItem->data->name = (char *)malloc(sizeof(char) * 20);
    if(pNewItem->data->name == NULL){

        printf("error");

    }

    //FILL IN
    printf("enter name..:");
    scanf("%s",pNewItem->data->name);

    pNewItem->data->number = dataToAdd;
    pNewItem->next = NULL;
    pNewItem->prev = NULL;

    //IF LIST IS EMPTY
    if(head == NULL){

        return pNewItem;

    }
    else{

        //SET 1: ITEM'S NEXT
        pNewItem->next = head;

        //SET 2: OLD HEAD'S PREV
        head->prev = pNewItem;

        //SET 3: NEW HEAD
        head = pNewItem;

        return head;
    }




}

//O(N)
//WE HAVE TWO CASE
//OUR WORST CASE IS IN CASE2
//IN CASE 2 WE MUST FIND LAST ITEM SO
//WE MUST TRAVEL ALL LIST
DLLI *addItemToEnd(DLLI *head, int dataToAdd)
{

    //CREATE ITEM
     DLLI *pNewItem;
     pNewItem = (DLLI *)malloc(sizeof(DLLI));
     if(pNewItem == NULL){

        printf("error");

     }

     pNewItem->data = (Student *)malloc(sizeof(Student));
     if(pNewItem->data == NULL){

        printf("error");

     }

     pNewItem->data->name = (char *)malloc(sizeof(char) * 20);
     if(pNewItem->data->name == NULL){

        printf("error");

     }

     //FILL IN
     printf("enter name..:");
     scanf("%s",pNewItem->data->name);

     pNewItem->data->number = dataToAdd;
     pNewItem->next = NULL;
     pNewItem->prev = NULL;

     //IF LIST HAS NO ITEM
     if(head == NULL){

        return pNewItem;

     }
     else{//IF LIST HAS AT LEAST ONE ITEM


        DLLI *temp;
        temp = head;

        while(temp->next != NULL){

            temp = temp->next;

        }

        //SET 1: TEMP'S NEXT
        temp->next = pNewItem;

        //SET 2: ITEM'S PREV
        pNewItem->prev = temp;

        return head;

     }




}


//O(N)
//WE PRINT LIST ONE BY ONE
//SO WE TRAVEL ALL LIST
void printList(DLLI *head)
{

    while(head != NULL){

        printf("name..:%s\n",head->data->name);
        printf("number..:%d\n",head->data->number);
        head = head->next;
    }


}

//O(N)
//WE HAVE TWO CASE
//OUR WORST CASE IS IN CASE2
//IN CASE 2 IF ITEM THAT WE NEED TO DELETE AT LAST INDEX
//WE MUST TRAVEL ALL LIST
DLLI* double_linked_remove(DLLI* head, int dataToDel)
{
    // EMPTY LIST CHECK
    if (NULL != head) {
        DLLI* temp = head;

        while(NULL != temp && temp->data->number != dataToDel)
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

//O(2 * (N + 1)) => O(2N + 2) => O(N)
//recursive functions return using the same path
//there is a base case so we add +1 step in to the big o
//n + 1 step go
//n + 1 step return
void printListRec(DLLI *head)
{
    //BASE CASE
    if(head == NULL){

        return;

    }

    printf("(RECURSIVE)name..:%s\n",head->data->name);
    printf("(RECURSIVE)number..%d\n",head->data->number);

    printListRec(head->next);



}



