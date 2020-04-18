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
void deleteAtHead(node *&head)
{
    if(head==NULL)
        return ;
    node *temp = head;
    head = temp->next;
    delete temp;
    return;
}
void deleteAtTail(node *head)
{
    node * prev = NULL;
    if(head==NULL)
        return;
    while(head->next!=NULL)
    {
        prev = head;
        head=head->next;
    }
    //node* temp = head->next;
    delete head;
    prev->next = NULL;
    return;
}
void deleteAtN(node* head, int n)
{
    if(n==1)
        deleteAtHead(head);
    if(n>=length(head))
        deleteAtTail(head);
    else
    {
        node* prev = NULL;
        for(int i=0;i<n-1;i++)
        {
            prev = head;
            head=head->next;
        }
        prev->next = head->next;
        delete head;
    }
    return;

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
    deleteAtHead(head);
    deleteAtTail(head);
    Print(head);
    deleteAtN(head,3);
    Print(head);

    return 0;
}
