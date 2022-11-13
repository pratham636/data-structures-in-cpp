#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void insert(node* &head,int val)
{
        node* n=new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}

void display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<endl;
}
int length(node* head)
{
    int l=0;
    node* temp=head;
    while(temp!=NULL)
    {
        l++;
        temp=temp->next;   
    }
    return l;
}

node* kappend(node* &head,int k)
{
    node* newHead;
    node* newtail;
    node* tail=head;
    int l=length(head);
    int count=1;
    k=k%l;
    while(tail->next!=NULL)
    {
        if(count==l-k)
        {
            newtail=tail;
        }
        if(count==l-k+1)
        {
            newHead=tail;
        }
    tail=tail->next;
    count++;
    }
newtail->next=NULL;
tail->next=head;
return newHead;
}

int main()
{
    node* head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    display(head);
    //deleat(head,1);
    //node* n=reves(head);
    //display(n);
    //node* m=reves_recursive(head);
    int k=3;
    node* h=kappend(head,k);    
    display(h);

    return 0;
}