#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode(int data)
{
    struct node *temp = (struct node*) malloc (sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct node *buildTree(int arr[], int n, int i)
{
    if (i >= n || arr[i] == -1)
    {
        return NULL;
    }
    struct node *root = newnode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);
    return root;
}
int validBST(struct node *root, struct node *min, struct node *max)
{
    if (root == NULL) return 1;
    if (min != NULL && root->data <= min->data) return 0;
    if (max != NULL && root->data >= max->data) return 0;
    return validBST(root->left, min, root) && validBST(root->right, root, max);
}
void freeNode(struct node *root)
{
    if (root == NULL) return;
    freeNode(root->left);
    freeNode(root->right);
    free(root);
}
int main()
{
    int n;
    printf("Enter total number of nodes in the binary tree: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d nodes in level order (-1 for NULL):\n", n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    struct node *root = buildTree(arr, n, 0);
    if (validBST(root, NULL, NULL))
    {
        printf("True: The given binary tree is a valid BST.");
    }
    else
    {
        printf("False: The given binary tree is not a valid BST.");
    }
    freeNode(root);
    return 0;
}