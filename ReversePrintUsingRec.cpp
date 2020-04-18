#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
void Print(node* temp)
{
    if(temp==NULL)
        return;
    cout<<temp->data<<" ";
    Print(temp->next);
}
void ReversePrint(node* temp)
{
    if(temp==NULL)
        return;
    ReversePrint(temp->next);
    cout<<temp->data<<" ";
}
node* Insert(node* head, int data)
{
    node* temp= new node();
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        node* temp1=head;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
    return head;
}
int main()
{
    node* head=NULL;
    head=Insert(head,5);
    head=Insert(head,6);
    head=Insert(head,8);
    head=Insert(head,4);
    head=Insert(head,7);
    Print(head);
    cout<<endl;
    ReversePrint(head);
    return 0;
}
