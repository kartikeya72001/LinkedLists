#include <iostream>
#include<cstdlib>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* Head;
void Insert(int data){
    Node * temp = new Node();
    temp->data=data;
    temp->next=Head;
    Head=temp;
}
void Print(){
    Node* temp=Head;
    cout<<"List is: ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void Delete(int n){
    Node* temp =Head;
    if(n==1){
        Head=temp->next;
        free(temp);
        return;
    }
    for(int i=0;i<n-2;i++){
        temp=temp->next;
    }
    Node* temp2=temp->next;
    temp->next=temp2->next;
    free(temp2);
}
int main() {
    int data;
    Head=NULL;
    int n;
    cout<<"Enter the numbers of elements"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter The element"<<endl;
        cin>>data;
        Insert(data);
    }
    Print();
    cout<<"Enter element position to be deleted"<<endl;
    cin>>n;
    Delete(n);
    Print();
    return 0;
}
