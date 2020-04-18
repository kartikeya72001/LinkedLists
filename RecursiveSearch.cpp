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
void insertAtHead(node *&head, int data)
{
    node *n = new node(data);
    n->next=head;
    head=n;
}
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
void insertInMiddle(node *&head, int data, int n)
{
    if(head==NULL || n==0)
        insertAtHead(head,data);
    else if(n>length(head))
    {
        InsertAtTail(head,data);
    }
    else
    {
        int jump=1;
        node *temp1 = head;
        while(jump<=n-1)
        {
            temp1=temp1->next;
            jump++;
        }
        node *n = new node(data);
        n->next=temp1->next;
        temp1->next=n;
    }
}
bool Search(node* head, int k)
{
    if(head==NULL)
        return false;
    if(head->data==k)
        return true;
    else
        return Search(head->next, k);
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
int main()
{
    node* head = NULL;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    InsertAtTail(head,6);
    insertInMiddle(head,2,3);
    insertAtHead(head,8);
    insertAtHead(head,2);

    Print(head);
    if(Search(head,3))
        cout<<"Element is Present"<<endl;
    else
        cout<<"Element is absent"<<endl;
    return 0;
}
