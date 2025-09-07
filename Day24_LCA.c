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
struct node *LCA(struct node *root, int p, int q)
{
    if (root == NULL) return NULL;
    if (root->data == p || root->data == q) return root;
    struct node *left = LCA(root->left, p, q);
    struct node *right = LCA(root->right, p, q);
    if (left && right) return root;
    if (left != NULL) return left; 
    else return right;
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
    int p, q;
    printf("Enter two nodes to find their Lowest Common Ancestor (LCA): ");
    scanf("%d %d", &p, &q);
    struct node *lca = LCA(root, p, q);
    printf("Lowest Common Ancestor of %d and %d is: %d", p, q, lca->data);
    freeNode(root);
    return 0;
}