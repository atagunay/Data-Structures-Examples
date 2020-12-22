#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
    int data;
    // struct Student data;
    // struct Student* data;
    struct tagNode* left;
    struct tagNode* right;
}Node;


Node *AddItemTree(Node *root, int dataToAdd);
void PrintTreePreorder(Node *root);
void PrintTreePreorder2(Node *root);
void PrintTreeInorder(Node *root);
void PrintTreeInorder2(Node *root);
void PrintTreePostorder(Node *root);
void PrintTreePostorder2(Node *root);

int main()
{
    int i;
    int selection;
    Node* root = NULL;

    while( i != 99){

        printf("1 -> ADD DATA\n");
        printf("2 -> PRINT TREE PREORDER  (1)\n");
        printf("3 -> PRINT TREE PREORDER  (2)\n");
        printf("4 -> PRINT TREE INORDER   (1)\n");
        printf("5 -> PRINT TREE INORDER   (2)\n");
        printf("6 -> PRINT TREE POSTORDER (1)\n");
        printf("7 -> PRINT TREE POSTORDER (2)\n");
        printf("-->");

        scanf("%d",&i);

        if(selection == 1){

            int number;

            printf("Enter data to  add..:");
            scanf("%d",&number);

            root = AddItemTree(root,number);

        }

        else if(selection == 2){

            PrintTreePreorder(root);

        }

        else if(selection == 3){

            PrintTreePreorder2(root);

        }

        else if(selection == 4){

            PrintTreeInorder(root);

        }

        else if(selection == 5){

            PrintTreeInorder2(root);

        }

        else if(selection == 6){

            PrintTreePostorder(root);

        }

        else if(selection == 7){

            PrintTreePostorder2(root);


        }


    }



    return 0;
}

//O(LOG(N) + 1) -> O(LOG(N))
//THERE ARE 2 RECOURSIVE FUNCTIONS
//BUT EACH STEPS ONLY ONE OF THEM WILL WORK
//IF WE GO RIGHT WE WILL NOT THÝNK ABOUT THE LEFT HALF
//SIMILARLY,IF WE GO LEFT WE WILL NOT THINK ABOUT THE RIGHT HALF
Node *AddItemTree(Node *root, int dataToAdd)
{
    //BASE CASE
    if (NULL == root) {

        Node* pNewNode;
        pNewNode = (Node*) malloc(sizeof(Node));
        if (NULL == pNewNode) {

            printf("AddItemToTree - Can NOT allocate memory\n");
            exit(EXIT_FAILURE);

        }


        //PREPARE A LEAF NODE
        pNewNode->left = NULL;
        pNewNode->right = NULL;
        pNewNode->data = dataToAdd;

        return pNewNode;
    }
    else{

        if(root->data < dataToAdd){

            //GO RIGHT
            root->right = AddItemTree(root->right,dataToAdd);

        }
        else{

            //GO LEFT
            root->left = AddItemTree(root->left, dataToAdd);
        }


      return root;
    }


}

// O(N + 3N) -> O(3N) -> O(N)
//AND WE MUST VISIT EVERY NODE O(N)
//WE SHOULD NOT FORGET TO BASE CASE
//WE HIT BASE CASE LEAF * 2 TIMES O(2N)
void PrintTreePreorder(Node *root)// ROOT - X - X
{
    //BASE CASE
    if(root == NULL){

        return;
    }

    //ROOT - RIGT SIDE - LEFT SIDE
    printf("%d\n",root->data);
    PrintTreePreorder(root->right);
    PrintTreePreorder(root->left);
}
void PrintTreePreorder2(Node *root)// ROOT - X - X
{
    //BASE CASE
    if(root == NULL){

        return;

    }

    //ROOT - LEFT SIDE - RIGHT SIDE
    printf("%d\n",root->data);
    PrintTreePreorder2(root->left);
    PrintTreePreorder2(root->right);
}

void PrintTreeInorder(Node *root)// X - ROOT - X
{
    //BASE CASE
    if(root == NULL){

        return;
    }

    //RIGHT SIDE - ROOT - LEFT SIDE
    PrintTreeInorder(root->right);
    printf("%d\n",root->data);
    PrintTreeInorder(root->left);

}
void PrintTreeInorder2(Node *root)// X - ROOT - X
{
    // BASE CASE
    if(root == NULL){

        return;

    }

    // LEFT SIDE - ROOT - RIGHT SIDE
    PrintTreeInorder2(root->left);
    printf("%d\n",root->data);
    PrintTreeInorder2(root->right);


}
void PrintTreePostorder(Node *root)//X - X - ROOT
{
    //BASE CASE
    if(root == NULL){

        return;

    }

    //RIGHT SIDE - LEFT SIDE - ROOT
    PrintTreePostorder(root->right);
    PrintTreePostorder(root->left);
    printf("%d\n",root->data);


}
void PrintTreePostorder2(Node *root)// X - X - ROOT
{

    //BASE CASE
    if(root == NULL){

        return;

    }

    //LEFT SIDE - RIGHT SIDE - ROOT
    PrintTreePostorder2(root->left);
    PrintTreePostorder2(root->right);
    printf("%d\n",root->data);



}
