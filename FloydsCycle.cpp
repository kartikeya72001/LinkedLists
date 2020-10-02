#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

// head - Head pointer of the Linked List
// Return a boolean value indicating the presence of cycle
// If the cycle is present, modify the linked list to remove the cycle as well
void CycleRemove(Node *&head)
{
    Node *slow = head;
	Node *fast = head;
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
bool floydCycleRemoval(Node *h)
{
    Node *slow_p = h, *fast_p = h;

        while (slow_p && fast_p && fast_p->next) {
            slow_p = slow_p->next;
            fast_p = fast_p->next->next;
            if (slow_p == fast_p) {
                CycleRemove(h);
                return true;
            }
        }
        return false;
}

bool CycleDetect(Node* h)
{
    Node* head = h;
    unordered_set<Node*> s;
    while (h != NULL) {
        if (s.find(h) != s.end())
        {
            CycleRemove(head);
            return true;
        }
        s.insert(h);
        h = h->next;
    }

    return false;
}

void buildCycleList(Node *&head)
{
    unordered_map<int, Node *> hash;
    int x;
    cin >> x;
    if (x == -1)
    {
        head = NULL;
        return;
    }
    head = new Node(x);
    hash[x] = head;
    Node *current = head;
    while (x != -1)
    {
        cin >> x;
        if (x == -1)
            break;
        if (hash.find(x) != hash.end())
        {
            current->next = hash[x];
            return;
        }
        Node *n = new Node(x);
        current->next = n;
        current = n;
        hash[x] = n;
    }
    current->next = NULL;
}

void printLinkedList(Node *head)
{
    unordered_set<int> s;
    while (head != NULL)
    {
        if (s.find(head->data) != s.end())
        {
            cout << "\nCycle detected at " << head->data;
            return;
        }
        cout << head->data << " ";
        s.insert(head->data);
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;

    buildCycleList(head);

    bool cyclePresent = floydCycleRemoval(head);
    if (cyclePresent)
    {
        cout << "Cycle was present\n";
    }
    else
    {
        cout << "No cycle\n";
    }

    cout << "Linked List - ";
    printLinkedList(head);

    return 0;
}
