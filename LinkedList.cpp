#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

void PrintList(Node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
}
void IncrementData(Node* n)
{
    while(n!=NULL)
    {
        n->data++;
        n=n->next;
    }
}
int main()
{
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;

	// allocate 3 nodes in the heap
	head = new Node();
	second = new Node();
	third = new Node();

	head->data = 1; // assign data in first node
	head->next = second; // Link first node with
	// the second node

	// assign data to second node
	second->data = 2;

	// Link second node with the third node
	second->next = third;

	third->data = 3; // assign data to third node
	third->next = NULL;
	PrintList(head);
	IncrementData(head);
	cout<<endl;
	PrintList(head);
	return 0;
}
