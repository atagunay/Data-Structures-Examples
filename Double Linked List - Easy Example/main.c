#include <stdio.h>
#include <stdlib.h>

typedef struct tagDoublyLinkedList {

    int data; // A single integer will be stored as data
    struct tagDoublyLinkedList* prev;
    struct tagDoublyLinkedList* next;

}DLLI;

DLLI *AddItemToEnd(DLLI *head, int dataToAdd);
DLLI *AddItemToHead(DLLI *head, int dataToAdd);
DLLI *DeleteItem(DLLI *head, int dataToDel);
DLLI* DeleteItemOptimized(DLLI* head, int dataToDel);
void PrintList(DLLI *head);

int main()
{
    DLLI *head;
    head = NULL;

    int selection = 0;

    while(selection != 99){

        printf("1-> ADD ITEM TO END\n");
        printf("2-> ADD ITEM TO HEAD\n");
        printf("3-> DELETE ITEM\n");
        printf("4-> DELETE ITEM WITH OPTMIZED FUNCTION\n");
        printf("5-> PRINT LIST\n");
        printf("->");
        scanf("%d",&selection);

        if(selection == 1){

            int number;

            printf("Enter Data To Add..:");
            scanf("%d",&number);

            head = AddItemToEnd(head, number);

        }
        else if(selection == 2){

            int number;

            printf("Enter Data To Add..:");
            scanf("%d",&number);

            head = AddItemToHead(head, number);

        }

        else if(selection == 3){

            int number;

            printf("Enter Data To Delete..:");
            scanf("%d",&number);

            head = DeleteItem(head, number);

        }

        else if(selection == 4){

             int number;

            printf("Enter Data To Delete..:");
            scanf("%d",&number);

            head = DeleteItemOptimized(head, number);

        }

        else if(selection == 5){

            PrintList(head);

        }

    }


    return 0;
}

//O(N)
//WE HAVE TWO CASE
//OUR WORST CASE IS IN CASE2
//IN CASE 2 WE MUST FIND LAST ITEM SO
//WE MUST TRAVEL ALL LIST
DLLI *AddItemToEnd(DLLI *head, int dataToAdd)
{
    //STEP 1 -> CREATE NEW ITEM
    DLLI *pNewItem;
    pNewItem = (DLLI *)malloc(sizeof(DLLI));
    if(pNewItem == NULL){

        printf("AddItemToEnd - ERROR : Cannot allocate memory for item...\n");
        exit(EXIT_FAILURE);

    }

    //STEP 2 -> FILL IN
    pNewItem->data = dataToAdd;
    pNewItem->next = NULL;
    pNewItem->prev = NULL;

    //CASE 1 -> LIST IS EMPTY
    if(head == NULL){

        return pNewItem;

    }
    else{

        DLLI *temp;
        temp = head;

        //FIND LAST ITEM
        while(temp->next != NULL){

            temp = temp->next;

        }

        //SET 1: LAST ITEM'S NEXT IS pNewItem
        temp->next = pNewItem;

        //SET 2: pNewItem'S PREV IS temp
        pNewItem->prev = temp;


        return head;
    }

}
//O(1)
//WE ADD ITEM TO HEAD
//SO WE DONT HAVE TO LOOK ALL ITEMS ONE BY ONE
//OUR FUNCTION WORKS ONLY ONE TIME AND THEN FINIS THE TASK
DLLI *AddItemToHead(DLLI *head, int dataToAdd)
{
    //CREATE ITEM
    DLLI *pNewItem;
    pNewItem = (DLLI *)malloc(sizeof(DLLI));
    if(pNewItem == NULL){

        printf("AddItemToHead - ERROR : Cannot allocate memory for item...\n");
        exit(EXIT_FAILURE);

    }

    //FILL IN
    pNewItem->data = dataToAdd;
    pNewItem->next = NULL;
    pNewItem->prev = NULL;

    //CASE 1 -> LIST IS EMPTY
    if(head == NULL){

        return pNewItem;

    }
    else{//CASE 2 -> LIST HAS AT LEAST ONE ITEM

        //SET 1: NEW ITEM NEXT IS HEAD
        pNewItem->next = head;

        //SET2: HEAD POINT OUT NEW ITEM
        head = pNewItem;

        return head;
    }

}

//O(N)
//WE HAVE TWO CASE
//OUR WORST CASE IS IN CASE2
//IN CASE 2 IF ITEM THAT WE NEED TO DELETE AT LAST INDEX
//WE MUST TRAVEL ALL LIST
DLLI *DeleteItem(DLLI *head, int dataToDel)
{
    //CASE 1 -> LIST IS EMPTY
    if(head == NULL){

         printf("list is empy");
        return head;

    }
    else{//CASE 2 -> LIST HAST AT LEAST ONE ITEM

        DLLI *temp;
        temp = head;

        //FIND ITEM TO DELETE
        while(temp->data != dataToDel && temp != NULL){

            temp = temp->next;
        }


        //AFTER WHILE, TEMP RETURN WITH NULL
        //SO THERE IS NOT DATA TO DELETE
        if(temp == NULL){

            printf("can not find item to delete");
            return head;

        }
        else{//ITEM FOUND

            //SET 1: PREVIOUS ITEM'S NEXT VALUE
            //IF TEMP IS NOT FIRST ITEM
            if(temp->prev != NULL){

                temp->prev->next = temp->next;

            }

            //SET 2: NEXT ITEM'S PREVIOUS VALUE
            //IF TEMP IS NOT LAST ITEM
            if(temp->next != NULL){

                temp->next->prev = temp->prev;

            }

            if(head == temp){

                head = temp->next;

            }

            free(temp);
            return head;
        }

    }


}

//O(N)
//WE PRINT LIS ONE BY ONE
//SO WE TRAVEL ALL LIST
void PrintList(DLLI *head)
{
    int counter = 1;

    while(head != NULL){

        printf("%d . data..:%d\n",counter,head->data);
        head = head->next;
        counter = counter + 1;
    }


}

//O(N)
//WE HAVE TWO CASE
//OUR WORST CASE IS IN CASE2
//IN CASE 2 IF ITEM THAT WE NEED TO DELETE AT LAST INDEX
//WE MUST TRAVEL ALL LIST
DLLI* DeleteItemOptimized(DLLI* head, int dataToDel)
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

