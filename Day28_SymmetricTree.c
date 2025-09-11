#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct node *buildtree(int arr[], int n, int i)
{
    if (i>=n || arr[i]==-1)
    {
        return NULL;
    }
    struct node *root = newnode(arr[i]);
    root->left = buildtree(arr, n, 2*i+1);
    root->right = buildtree(arr, n, 2*i+2);
    return root;
}
int checkSymmetry(struct node *l, struct node *r)
{
    if (l==NULL && r==NULL)
    {
        return 1;
    }
    if (l==NULL || r==NULL)
    {
        return 0;
    }
    int l_mirror = checkSymmetry(l->left, r->right);
    int r_mirror = checkSymmetry(l->right, r->left);
    if (l->data==r->data && l_mirror && r_mirror)
    {
        return 1;
    }
    return 0;
}
void freeTree(struct node *root)
{
    if (root==NULL)
    {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
int main()
{
    int n;
    printf("Enter number of nodes in binary tree: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d nodes in level order (-1 for NULL):\n", n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    struct node *root = buildtree(arr, n, 0);
    if (root == NULL || checkSymmetry(root->left, root->right))
    {
        printf("True: The binary tree is symmetric.");
    }
    else
    {
        printf("False: The binary tree is not symmetric.");
    }
    freeTree(root);
    return 0;
}