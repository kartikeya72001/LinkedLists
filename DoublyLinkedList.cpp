#include<iostream>
using namespace std;
struct node
{
    int data;
    node* prev;
    node* next;
};
node* head;
node* GetNewNode(int x)
{
    node* temp=new node();
    temp->data=x;
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
}
void Print()
{
    node* temp=head;
    cout<<"Forward: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void ReversePrint()
{
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    cout<<"Reverse: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<endl;
}
void InsertH(int x)
{
    node* temp=GetNewNode(x);
    if(head==NULL)
    {
        head=temp;
        return;
    }
    head->prev=temp;
    temp->next=head;
    head=temp;
}
int main()
{
    head=NULL;
    InsertH(2);
    InsertH(6);
    InsertH(4);
    InsertH(8);
    InsertH(7);
    Print();
    ReversePrint();
}
