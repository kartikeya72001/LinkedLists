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
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
void FloydCycle(node* head)
{
	node *slow = head;
	node *fast = head;
	fast = fast->next->next;
    slow = slow->next;
	while(fast->data!=slow->data)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	slow = head;
	while(slow->next->data!=fast->next->data)
	{
		fast = fast->next;
		slow = slow->next;
	}
	fast->next = NULL;
	return;
}
int main()
{
    node *head = NULL;
    int data = 0;
	cin>>data;
	while(data!=-1)
	{
		InsertAtTail(head,data);
		cin>>data;
	}
	//Print(head);
	FloydCycle(head);
	Print(head);
    return 0;
}
