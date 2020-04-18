#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
node* head;
void Insert(int data)
{
    node* temp =new node();
    temp->data=data;
    temp->next=head;
    head=temp;
}
void Print()
{
    node* temp =head;
    cout<<"List is: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
node* Reverse()
{
    node *current, *next, *prev;
    current=head;
    prev=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
}
int main()
{
    head=NULL;
    cout<<"Enter Number of Insertions"<<endl;
    int n,x;
    cin>>n;
    cout<<"Enter the numbers to be added"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        Insert(x);
    }
    Print();
    Reverse();
    cout<<"Reversed ";
    Print();
    return 0;
}
