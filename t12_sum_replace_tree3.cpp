#include <stdlib.h>
#include <iostream>

using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
};

// New node creation
struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}

// Traverse Preorder
void traversePreOrder(struct node *temp) {
  if (temp == NULL) {
  return;
  }
    cout << " " << temp->data;
    traversePreOrder(temp->left);
    traversePreOrder(temp->right);
  
}

// Traverse Inorder
void traverseInOrder(struct node *temp) {
  if (temp != NULL) {
    traverseInOrder(temp->left);
    cout << " " << temp->data;
    traverseInOrder(temp->right);
  }
}

// Traverse Postorder
void traversePostOrder(struct node *temp) {
  if (temp != NULL) {
    traversePostOrder(temp->left);
    traversePostOrder(temp->right);
    cout << " " << temp->data;
  }
}

int count(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return count(root->left)+count(root->right)+1;
}
int sum_allnode(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return sum_allnode(root->left)+sum_allnode(root->right)+root->data;
}
void sum_replaqce(node *root)
{
    if(root==NULL)
    {
        return;
    }
    sum_replaqce(root->left);
    sum_replaqce(root->right);

    if(root->left!=NULL)
    {
        root->data+=root->left->data;
    }
    if(root->right!=NULL)
    {
        root->data+=root->right->data;
    }
}
int main() {
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7); 
  cout << "preorder traversal: ";
  traversePreOrder(root);
   // cout<<endl<<"count :"<<count(root)<<endl;
 //   cout<<"Sum of Node :"<<sum_allnode(root)<<endl;
    sum_replaqce(root);
    cout << endl << "preorder traversal: ";
    traversePreOrder(root);
    return 0;
}



 