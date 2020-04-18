#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* nodeB;
};
Node* head;
void Insert(int data, int n)
{
    Node* temp1=new Node();
    temp1->data=data;
    temp1->nodeB=NULL;
    if(n==1){
        temp1->nodeB=head;
        head=temp1;
        return;
    }
    Node* temp2=head;
    for(int i=0;i<n-2;i++)
    {
        temp2=temp2->nodeB;
    }
    temp1->nodeB=temp2->nodeB;
    temp2->nodeB=temp1;
}
int Size()
{
    Node* temp=head;
    int counter=0;
    while(temp!=NULL)
    {
        counter++;
        temp=temp->nodeB;
    }
    return counter;
}
void Print()
{
    Node* temp=head;
    cout<<"Linked List is: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp= temp->nodeB;

    }
    cout<<endl;
}
int main()
{
    head=NULL;
    int sizeOfLL=0;
    cout<<"Enter Number of Insertions"<<endl;
    int n,x,pos;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the numbers to be added and position"<<endl;
        cin>>x>>pos;
        sizeOfLL=Size();
        if(sizeOfLL+1<pos)
        {
            cout<<"Invalid Position!! Current size of List: "<<sizeOfLL<<endl;
            i--;

        }
        else{
            Insert(x,pos);
            Print();
        }
    }
    return 0;
}
