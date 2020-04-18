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
node* mergeLL(node* a, node* b)
    {
        if(a==NULL)
            return b;
        else if(b==NULL)
        {
            return a;
        }

        node *c;
        if(a->data < b->data)
        {
            c = a;
            c->next = mergeLL(a->next,b);
        }
        else
        {
            c = b;
            c->next = mergeLL(a,b->next);
        }
        return c;
    }
int main()
{
    int t;
	cin>>t;
	while(t>0)
	{
	    node *head1 = NULL;
        node *head2 = NULL;
		int n1;
		cin>>n1;
		for(int i=0;i<n1;i++)
		{
			int a;
			cin>>a;
			InsertAtTail(head1,a);
		}
		int n2;
		cin>>n2;
		for(int i=0;i<n2;i++)
		{
			int a;
			cin>>a;
			InsertAtTail(head2,a);
		}
		head1 = mergeLL(head1,head2);
		Print(head1);
		t--;
		delete head1;
		delete head2;
	}
    return 0;
}
