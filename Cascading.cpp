#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
    node(int d)
    {
        data = d;
        next=NULL;
    }
};
int length(node* head)
{
    int len=0;
    while(head!=NULL)
    {
        head=head->next;
        len++;
    }
    return len;
}
void InsertAtTail(node *&head, int data)
{
    if(head==NULL)
    {
        head = new node(data);
        return;
    }
    node* tail = head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    tail->next=new node(data);
    return;
}
void List(node *&head)
{
    int arr[100];
    cout<<"Enter Elements"<<endl;
    int i=0;
    do
    {
        cin>>arr[i];
        i++;
    }while(arr[i-1]!=-1);
    i=0;
    while(arr[i]!=-1)
    {
        InsertAtTail(head,arr[i]);
        i++;
    }
    return;
}
void Print(node *head)
{
    //node *temp = head;
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
istream& operator>> (istream &is, node *&head)
{
    List(head);
    return is;
}
ostream& operator<< (ostream &os, node *&head)
{
    Print(head);
    return os;
}
int main()
{
    node* head = NULL;
    cin>>head>>head;
    cout<<head;
    return 0;
}
