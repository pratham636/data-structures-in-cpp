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
void deleat(node* &head,int val)
{
    node* temp=head;
    if(head->data==val)
    {
        head=head->next;
        delete temp;
        return;
    }
    while(temp->next->data!=val)
    {
        temp=temp->next;
    }
    node* del=temp->next;
    temp->next=temp->next->next;
    delete del;
}
node* reves(node* &head)
{
    node* temp=head;
    node* nex=head->next;
    node* pre=NULL;
    while(temp!=NULL)
    {
        //cout<<2;
        nex=temp->next;
        temp->next=pre;
        pre=temp;
        temp=nex;
    }
    return pre;
}
node* reves_recursive(node* &head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    node *newhead=reves_recursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
node* reves_knode(node* &head,int k)
{
    node* temp=head;
    node* nex=head->next;
    node* pre=NULL;
    int count=0;
    while(temp!=NULL && count<k)
    {
        nex=temp->next;
        temp->next=pre;
        pre=temp;
        temp=nex;
        count++;
    }
    if(nex!=NULL)
    {
    head->next = reves_knode(nex,k);
    }
    return pre;
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
    //deleat(head,4);
    //node* n=reves(head);
    //display(n);
    //node* m=reves_recursive(head);
    int k=3;
    node* p=reves_knode(head,k);
    display(p);
    return 0;
}