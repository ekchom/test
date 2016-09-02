#include <stdio.h>
#include <stdlib.h>
/* Build a Random Tree */
/* Then preOrder 
 * Get Height 
 * Free the Tree 
 */
typedef struct node 
{
        int val ;
        struct node *left, *right;
}node_t; 
node_t *createNode(int val) 
{
    node_t *newNode=NULL;
    newNode = (node_t*) malloc(sizeof(node_t));
    if (newNode) 
    {
            newNode->val = val;
            newNode->left = newNode->right = NULL;
    }
    return newNode; 
}
void buildTree(node_t **root, int *a, int numElement) 
{
        node_t *temp = NULL;
        int i=0;
        if (!root)
                return;
        *root = createNode(a[0]);
        temp = *root;
        for (i=1; i<numElement;i++) 
        { 
                printf ("\n Parent %d, left %d ", temp->val, a[i]);
                temp->left = createNode(a[i]);
                i++;
                printf ("\n Parent %d, right %d ", temp->val, a[i]);
                temp->right = createNode(a[i]);
                if (i%3)
                        temp = temp->right;
                else 
                        temp =temp->left;
        } 
        printf ("\n");
} 
void preOrder(node_t *root) 
{
        if (!root) 
                return;
        preOrder(root->left);
        printf (" %d ", root->val);
        preOrder(root->right);
} 
int height_tree(node_t *root) 
{
        int lh=0, rh=0;
        if (!root)
                return 0;
        if (!root->left && !root->right)
                return 1;
        else 
        {
                lh =height_tree(root->left);
                rh = height_tree(root->right);
                return (lh>rh)?(lh+1):(rh+1);
        }
}
int height(node_t *root) 
{
        int h  = height_tree(root) ; 
        printf ("\nHeight of tree is %d \n", h);
} 
void freeNode(node_t *n) 
{ 
        if (!n)
                return;
        printf ("\n Freeing up Node %d ", n->val);
        free(n);
}
void deleteTree(node_t *root) 
{
        node_t *right=NULL;
        if (!root) 
                return ;
        right = root->right; 
        deleteTree(root->left);
        freeNode(root);
        deleteTree(right);
}
int main ()
{
        node_t *root=NULL;
        int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
        buildTree(&root, a, sizeof(a)/sizeof(a[0]));
        printf ("\n PreOrder Traversal "); 
        preOrder(root); 
        height(root);
        deleteTree(root);
        root=NULL;
}
