#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next=NULL;
    }
};
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
node* Midpoint(node* head)
{
    if(head==NULL || head->next==NULL)
        return head;
    node* slow = head;
    node*fast = head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
node* KFromLast(node *head, int k)
{
    node* fast = head;
    node* slow = head;
    for(int i=0;i<k;i++)
    {
        fast=fast->next;
    }
    while(fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    cout<<"Data: "<<slow->data<<" "<<fast->data<<endl;
    return slow;
}
int main()
{
    node *head = NULL;
    InsertAtTail(head,5);
    InsertAtTail(head,9);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    InsertAtTail(head,7);
    InsertAtTail(head,8);
    //InsertAtTail(head,1);
    Print(head);
    node* mid = Midpoint(head);
    cout<<mid->data<<endl;
    node *Kth = KFromLast(head,2);
    cout<<Kth->data<<endl;
    return 0;
}
