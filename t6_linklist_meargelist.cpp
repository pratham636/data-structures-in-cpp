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
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
node* mearge(node* &head,node* &head1)
{
    node* p1=head;
    node* p2=head1;
    node* dumm=new node(-1);
    node* p3=dumm;
    while(p1!=NULL&&p2!=NULL)
    {
        if(p1->data<p2->data)
        {
            p3->next=p1;
            p3=p3->next;
            p1=p1->next;
        }
        else
        {
            p3->next=p2;
            p3=p3->next;
            p2=p2->next;
        }
    //p3=p3->next;
    }
while(p1!=NULL)
        {
            p3->next=p1;
            p1=p1->next;
            p3=p3->next;
        }
while(p2!=NULL)
        {
            p3->next=p2;
            p2=p2->next;
            p3=p3->next;
        }
return dumm->next;    
}
int main()
{
    node* head=NULL;
    insert(head,1);
        insert(head,5);
            insert(head,7);
    insert(head,10);
    insert(head,15);
    display(head);
    node* head1=NULL;
    insert(head1,3);
        insert(head1,6);
            insert(head1,9);
    insert(head1,14);
    insert(head1,25);
    display(head1);
    node* j=mearge(head,head1);
    display(j);
    return 0;
}