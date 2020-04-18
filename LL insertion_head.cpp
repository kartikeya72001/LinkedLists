#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
node* head;
void Insert(int x)
{
    node* temp = new node;
    temp->data=x;
    temp->next=head;
    head=temp;
}
void Print()
{
    node* temp=head;
    cout<<"Linked List is: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp= temp->next;

    }
    cout<<endl;
}
int main()
{
    head=NULL;
    cout<<"Enter Number of Insertions"<<endl;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the numbers to be added"<<endl;
        cin>>x;
        Insert(x);
        Print();
    }
    return 0;
}
