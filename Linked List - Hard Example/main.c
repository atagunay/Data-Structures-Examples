#include <stdio.h>
#include <stdlib.h>

typedef struct TagStudent{

    char *name;
    char *surname;
    int id;
    double gpa;

}student;

typedef struct LinkedList{

    student *data;
    struct LinkedList *next;

}SLLI;

SLLI *addHead(SLLI *head);
void printList(SLLI *head);
SLLI *addLast(SLLI *head);
void printListRecursive(SLLI *head);
void printListReverseRecursive(SLLI *head);
SLLI *deleteList(SLLI *head);
SLLI *deleteItem(SLLI *head, int id);



int main()
{

    SLLI *head;
    head = NULL;

    int selection = 0;

    while(selection != 99){

    printf("1-> ADD HEAD\n");
    printf("2-> PRINT ALL LIST\n");
    printf("3-> ADD LAST\n");
    printf("4 -> PRINT LIST WITH RECURSIVE\n");
    printf("5 -> PRINT REVERSE LIST RECURSIVE\n");
    printf("6 -> DELETE ALL LIST\n");
    printf("7 -> DELETE ITEM BY ID\n");
    printf("-->");
    scanf("%d",&selection);

    if(selection == 1){

        head = addHead(head);

    }
    else if(selection == 2){

        printList(head);

    }
    else if(selection == 3){

        head = addLast(head);

    }
    else if(selection == 4){

        printListRecursive(head);
    }
    else if(selection == 5){

        printListReverseRecursive(head);

    }
    else if(selection == 6){

        head = deleteList(head);

    }
    else if(selection == 7){

        int item;

        printf("item for delete..:");
        scanf("%d",&item);

        head = deleteItem(head, item);

    }


    }



    return 0;
}

//O(1)
//all processes are constant job
//so this means it takes constant time
//the time of execution is not related to input size
SLLI *addHead(SLLI *head)
{

    SLLI *pItem;

    pItem = (SLLI *)malloc(sizeof(SLLI));
    if(pItem == NULL){

        printf("hata");

    }

    pItem->data = (student *)malloc(sizeof(student));
    if(pItem->data == NULL){

        printf("hata");

    }

    pItem->data->name = (char *)malloc(sizeof(char) * 20);
    if(pItem->data->name == NULL){

        printf("hata");

    }
    pItem->data->surname = (char *)malloc(sizeof(char) * 20);
    if(pItem->data->surname == NULL){

        printf("hata");

    }

    printf("name..:");
    scanf("%s",pItem->data->name);


    printf("surname..:");
    scanf("%s",pItem->data->surname);

    printf("id..:");
    scanf("%d",&(pItem->data->id));

    printf("gpa..:");
    scanf("%lf",&(pItem->data->gpa));


    if(head == NULL){

        pItem->next = NULL;
        head = pItem;

    }
    else{

        pItem->next = head;
        head = pItem;

    }





return head;
}

//O(N)
//while we printing the list
//we must go one by one so
//we must see all items in list
void printList(SLLI *head)
{

    if(head == NULL){

        printf("list is empty");
        return;
    }

    int item = 1;

    while(head != NULL){


        printf("%d. item's name %s\n",item,head->data->name);
        printf("%d. item's surname %s\n",item,head->data->surname);
        printf("%d. item's id %d\n",item,head->data->id);
        printf("%d. item's gpa %lf\n",item,head->data->gpa);

        head = head->next;
        item = item + 1;
    }

}

//O(N - 1) => O(N)
//we should think about the worst case for this function
//if list is not empty we must find the last item for add item as last item
//process that find last item visit the all items in the last
//our process n-1 step because of head->next
SLLI *addLast(SLLI *head)
{

    SLLI *pItem;

    //create pItem
    pItem = (SLLI *)malloc(sizeof(SLLI));
    if(pItem == NULL){

        printf("hata");
        exit(1);
    }

    pItem->data = (student *)malloc(sizeof(student));
    if(pItem->data == NULL){

        printf("hata");
        exit(1);
    }

    pItem->data->name = (char *)malloc(sizeof(char) * 20);
    if(pItem->data->name == NULL){


        printf("hata");
        exit(1);
    }

    pItem->data->surname = (char *)malloc(sizeof(char) * 20);
    if(pItem->data->surname == NULL){

        printf("hata");
        exit(1);
    }

    //fill pItem
    printf("name..:");
    scanf("%s",pItem->data->name);

    printf("surname..:");
    scanf("%s",pItem->data->surname);

    printf("id..:");
    scanf("%d",&(pItem->data->id));

    printf("gpa..:");
    scanf("%lf",&(pItem->data->gpa));

    //fill the list
    if(head == NULL){

        pItem->next = NULL;
        head = pItem;


    }
    else{

        SLLI *counter;
        counter = head;

        while(counter->next != NULL){

            counter = counter->next;

        }

        counter->next = pItem;
        pItem->next = NULL;


    }


    return head;
}

//O(2 * (N + 1)) => O(2N + 2) => O(N)
//recursive functions return using the same path
//there is a base case so we add +1 step in to the big o
//n + 1 step go
//n + 1 step return
void printListRecursive(SLLI *head)
{
    //base case
    if(head == NULL){

        return;
    }

    printf("(RECURSIVE)name %s\n",head->data->name);
    printf("(RECURSIVE)surname %s\n",head->data->surname);
    printf("(RECURSIVE)id %d\n",head->data->id);
    printf("(RECURSIVE)gpa %lf\n",head->data->gpa);
    printListRecursive(head->next);


}

//O(2 * (N + 1)) => O(2N + 2) => O(N)
//recursive functions return using the same path
//there is a base case so we add +1 step in to the big o
//n + 1 step go
//n + 1 step return
void printListReverseRecursive(SLLI *head)
{

    //base case
    if(head == NULL){

        return;

    }

    printListReverseRecursive(head->next);
    printf("(RECURSIVE)name %s\n",head->data->name);
    printf("(RECURSIVE)surname %s\n",head->data->surname);
    printf("(RECURSIVE)id %d\n",head->data->id);
    printf("(RECURSIVE)gpa %lf\n",head->data->gpa);



}

//O(N)
//main topic is so simple
//if we delete all list we must delete all item so we visit all item for delete
SLLI *deleteList(SLLI *head)
{
    SLLI *remove;

    while(head != NULL){

        remove = head;
        head = head->next;
        free(remove);
    }

    return head;
}

//O(N - 2) = O(N)
//we always think worst case for this function
//there are a lot of process but all processe excluding the while loop are constant jobs
//so the time is nor related to input size
//but for while loop, if deleting item in the last item on the list, it will be worst case
//in while loop we visit items with pItem->next->data so we go n - 2 steps
SLLI *deleteItem(SLLI *head, int id)
{

    SLLI *remove;
    SLLI *counter;

    counter = head;

    //list is empty
    if(head == NULL){

        printf("list is empty");
        return head;
    }

    //first item will delete
    else if(head->data->id == id){

        remove = head;
        head = head->next;
        free(remove);
    }

    //there is only item and next is null
    else if(head->next == NULL){

        printf("there is not an item for delete\n");
        return head;

    }

    else{

        while(counter->next->data->id != id){

            if(counter->next->next == NULL){

                printf("there is not an item for delete\n");
                return head;

            }

            counter = counter->next;


        }


        remove = counter->next;
        counter->next = counter->next->next;
        free(remove);

    }



   return head;
}
