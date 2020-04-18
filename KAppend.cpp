    #include<iostream>
    using namespace std;
    class node{
    public:
        int data;
        node *next;
        node(int d)
        {
            data = d;
            next = NULL;
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
    node* KAppend(node *head, int k)
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
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
    void ReversePrint(node* temp)
{
    if(temp==NULL)
        return;
    ReversePrint(temp->next);
    cout<<temp->data<<" ";
}
    int main()
    {
        int n;
        cin>>n;
        int x = n;
        node* head = NULL;
        while(n>0)
        {
            int a;
            cin>>a;
            InsertAtTail(head,a);
            n--;
        }
        int k;
        cin>>k;
        //Print(head);
        if(k%x==0 || x%k==0)
        {
            ReversePrint(head);
        }
        else
        {
            head = KAppend(head,k%x+1);
            Print(head);
        }
        return 0;
    }
