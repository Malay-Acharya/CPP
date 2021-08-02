#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        data = data;
        left = NULL;
        right = NULL;
    }
};

int search(int key, int inorder[], int st, int end)
{
    for(int i = st;i<=end;i++)
    {
        if(inorder[i] == key)
        return i;
    }
    return -1;
}

Node* maketree(int preorder[], int inorder[], int st, int end)
{
    static int idx = 0;
    if(st>end)
    {
        return NULL;
    }
    
    Node* node = new Node(preorder[idx]);
    if(st == end)
    {
        return node;
    }
    int v = search(preorder[idx], inorder, st, end);
    idx++;
    node->left = maketree(preorder, inorder, 0, v-1);
    node->right = maketree(preorder, inorder, v+1, end);
    return node;
}

void Inorder(Node* head)
{
    if(head== NULL)
    return;

    Inorder(head->left);
    cout<<head->data<<" ";
    Inorder(head->right);
}

int main()
{
    
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,3,5};

    Node* head = maketree(preorder, inorder, 0, 4);

    Inorder(head);
}