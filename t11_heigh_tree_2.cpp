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
  if (temp != NULL) {
    cout << " " << temp->data;
    traversePreOrder(temp->left);
    traversePreOrder(temp->right);
  }
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
      
int height(node* root) 
{
  if(root==NULL)
  {
    return 0;
  }
  int lefth=height(root->left);
  int right=height(root->right);
  return max(lefth,right)+1;
}
int calDiameter(node *root)
{
  if(root==NULL)
  {
    return 0;
  }
  int lheigh=height(root->left);
  int rheigh=height(root->right);
  int currDiameter=lheigh+rheigh+1;
  
  int lDiameter=calDiameter(root->left);
  int rDiameter=calDiameter(root->right);
 
  return max(currDiameter,max(lDiameter,rDiameter));
}



int main() 
{
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  cout << "preorder traversal: ";
  traversePreOrder(root);
  cout<<endl;
    //cout<<endl<<"count :"<<count(root)<<endl;
    //cout<<"Sum of Node :"<<sum_allnode(root)<<endl;
    //cout<<"height : "<<height(root)<<endl;
    cout<<"MaxDiameter : "<<calDiameter(root)<<endl;
    return 0;
}
