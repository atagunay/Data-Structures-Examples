#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    int id;
    char *Name;
}student;

typedef struct tagNode {
    struct Student* data;
    //struct Student data;
    struct tagNode* left;
    struct tagNode* right;
}Node;

Node *addItemToTreeRec(Node *root, int dataToAdd);
void PrintTreePreorder(Node *root);

int main()
{

    Node *root;
    root = NULL;

    int i = 0;

    for(i = 0;i<3;i++){

        int id;

        printf("enter id..:");
        scanf("%d",&id);

        root = addItemToTreeRec(root,id);

    }


    PrintTreePreorder(root);

 return 0;
}

Node *addItemToTreeRec(Node *root, int dataToAdd)
{
    //BASE CASE
    if(root == NULL){

        //CREATE ITEM
        Node *pNewItem;
        pNewItem = (Node *)malloc(sizeof(Node *));
        if(pNewItem == NULL){

            printf("hata");

        }

        pNewItem->data = (student *)malloc(sizeof(student));
        if(pNewItem->data == NULL){

            printf("hata");

        }

        pNewItem->data->Name = (char *)malloc(sizeof(char) * 20);
        if(pNewItem->data->Name == NULL){

            printf("hata");

        }

        //FILL IN
        pNewItem->data->id = dataToAdd;
        pNewItem->left = NULL;
        pNewItem->right = NULL;

        printf("name..:");
        scanf("%s",pNewItem->data->Name);

        return pNewItem;

    }
    else{

        if(root->data->id < dataToAdd){

            //GO RIGHT
            root->right = addItemToTreeRec(root->right,dataToAdd);

        }
        else{

            //GO LEFT
            root->left = addItemToTreeRec(root->left, dataToAdd);

        }


        return root;
    }


}
void PrintTreePreorder(Node *root)// ROOT - X - X
{
    //BASE CASE
    if(root == NULL){

        return;
    }

    //ROOT - RIGT SIDE - LEFT SIDE
    printf("%d\n",root->data->id);
    printf("%s\n",root->data->Name);
    PrintTreePreorder(root->right);
    PrintTreePreorder(root->left);
}

