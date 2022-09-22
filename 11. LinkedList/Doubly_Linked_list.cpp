#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node *prev;
    int data;
    Node *next;
};

// Global Variable
Node *first;

void Create(int A[], int n){
    Node *t, *last;

    first = new Node;
    first->data = A[0];
    first->next = first->prev = NULL;
    last = first;

    for (int i = 1; i < n; i++){
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display(Node *p){
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int Length(Node *p){
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

void Insert(Node *p, int index, int x){
    Node *t;

    if (index < 0 || index > Length(p)){
        return;
    }
    t = new Node;
    t->data = x;
    if (index == 0){
        t->prev= NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else{
        for(int i=0;i<index-1;i++){
            p = p->next;
        }
        t->next = p->next;
        t->prev = p;
        if(p->next){
            p->next->prev = t;
        }
        p->next = t;

    }
}

int Delete(Node *p,int pos){
    int x = -1;
    if(pos<1 || pos>Length(p)){
        return -1;
    }
    if(pos==1){
        first = first->next;
        if(first){
            first->prev = NULL;
        }
        x = p->data;
    }
    else{
        for(int i=0;i<pos-1;i++){
            p = p->next;
        }
        p->prev->next = p->next;
        if(p->next){
            p->next->prev = p->prev;
        }
        x = p->data;
    }
    return x;
}
int main(){
    int A[] = {2, 6, 3, 7, 4};

    Create(A, 5);
    cout << "Length : " << Length(first) << "\n";
    Display(first);
    cout<<"\n";
    Delete(first,5);
    Display(first);


    return 0;
}