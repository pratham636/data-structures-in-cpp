#include <bits/stdc++.h>
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
void rightview(node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
          int n=q.size();
          for(int i=0;i<n;i++)
          {
            node* curr=q.front();
            q.pop();
            if(i==n-1)
            {
              cout<<curr->data<<" ";
            }
            if(curr->left!=NULL)
            {
              q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
              q.push(curr->right);
            }
          }
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
  root->left->left->left = newNode(8); 
  root->left->left->right = newNode(9); 
  root->left->right->left = newNode(10); 
  root->left->right->right = newNode(11); 
  root->right->left->left = newNode(12); 
  root->right->left->right = newNode(13); 
  root->right->right->left = newNode(14); 
  root->right->right->right = newNode(15); 
  //cout << "preorder traversal: ";
  //traversePreOrder(root);
  rightview(root);
  return 0;
}



 