#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
    node(int d)
    {
        data = d;
        next=NULL;
    }
};

void Print(node *head)
{
    //node *temp = head;
    while(head!=NULL)
    {
        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<endl;
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

void SortList(node* head)
{
    node *temp1 = head->next;
    node *temp2 = head;

    while(temp1->next != NULL)
    {
        temp2 = head;
        while(temp2->next->data < temp1->data)
        {
            temp2 = temp2->next;
        }
        swap(temp1->data,temp2->data);
        Print(head);
        temp1 = temp1->next;
    }
    return;
}

int main(int argc, char const *argv[]) {
    node* head = NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        InsertAtTail(head,x);
    }
    SortList(head);
    Print(head);
    return 0;
}
