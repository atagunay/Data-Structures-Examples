#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    int id;
    char *Name;
}student;

typedef struct tagNode {
// struct Student* data;
    struct Student data;
    struct tagNode* left;
    struct tagNode* right;
}Node;

Node *addItemToTreeRec(Node *root, int dataToAdd);
void PrintTreePreorder2(Node *root);

int main()
{
    Node *root;
    root = NULL;

    int i = 0;

    for(i = 0;i<3;i++){

        int id;

        printf("id..:");
        scanf("%d",&id);

        root = addItemToTreeRec(root,id);

    }

    PrintTreePreorder2(root);

    return 0;
}

//O(LOG(N) + 1) -> O(LOG(N))
//THERE ARE 2 RECOURSIVE FUNCTIONS
//BUT EACH STEPS ONLY ONE OF THEM WILL WORK
//IF WE GO RIGHT WE WILL NOT THINK ABOUT THE LEFT HALF
//SIMILARLY,IF WE GO LEFT WE WILL NOT THINK ABOUT THE RIGHT HALF
//FOR EX: WE HAVE 16 ELEMENTS IN TREE AND THIS FUNCTION GO THAT WAY
//16 - 8 - 4 - 2 - 1 => 5 ELEMENT
//2^4 => 16 => 16 =  LOG(N) + 1
Node *addItemToTreeRec(Node *root, int dataToAdd)
{
    //BASE CASE
    if(root == NULL){

        //CREATE ITEM
        Node *pNewItem;
        pNewItem = (Node *)malloc(sizeof(Node));
        if(pNewItem == NULL){

            printf("hata");

        }

        pNewItem->data.Name = (char *)malloc(sizeof(char) * 20);
        if(pNewItem->data.Name == NULL){

            printf("hata");
        }

        //FILL IN
        printf("enter name..:");
        scanf("%s",pNewItem->data.Name);

        pNewItem->left = NULL;
        pNewItem->right = NULL;
        pNewItem->data.id = dataToAdd;

       return pNewItem;

    }else{

        if(root->data.id < dataToAdd){

            //GO RIGHT
            root->right = addItemToTreeRec(root->right, dataToAdd);

        }
        else{
            // GO LEFT
            root->left = addItemToTreeRec(root->left, dataToAdd);
        }


        return root;
    }



}

// O(N + 2N) -> O(3N) -> O(N)
//AND WE MUST VISIT EVERY NODE O(N)
//WE SHOULD NOT FORGET TO BASE CASE
//WE HIT BASE CASE LEAF * 2 TIMES O(2N)
void PrintTreePreorder2(Node *root)// ROOT - X - X
{
    //BASE CASE
    if(root == NULL){

        return;

    }

    //ROOT - LEFT SIDE - RIGHT SIDE
    printf("id..:%d\n",root->data.id);
    printf("name..%s\n",root->data.Name);
    PrintTreePreorder2(root->left);
    PrintTreePreorder2(root->right);
}

