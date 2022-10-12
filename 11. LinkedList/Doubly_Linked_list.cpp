#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node *prev;
        int data;
        Node *next;
};

class DoublyLL{
    private:
        Node *head;
    public:

        DoublyLL(){
            head->next = head->prev = NULL;
        }
        DoublyLL(int A[],int n){
            Node *last,*t;
            head = new Node;
            head->data = A[0];
            head->prev = head->next = NULL;
            last = head;

            for(int i=1;i<n;i++){
                t = new Node;
                t->data = A[i];
                last->next = t;
                t->prev = last;
                t->next = NULL;
                last = t;
            }
        }

        void display(){
            Node *p = head;
            while(p!=NULL){
                cout<<p->data<<" ";
                p = p->next;
            }
        }

        int count(){
            Node *p = head;
            int count = 0;
            while(p!=NULL){
                count++;
                p = p->next;
            }
            return count;
        }

        void insert(int pos,int val){
            Node *p = head;
            if(pos<0 || pos>count()){
                return;
            }
            if(pos==0){
                Node *t;
                t = new Node;
                t->data = val;
                t->next = head;
                head->prev = t;
                head = t;
            }
            else{
                for(int i=0;i<pos-1;i++){
                    p = p->next;
                }
                Node *t;
                t = new Node;
                t->data = val;
                t->next = p->next;
                t->prev = p;
                if(p->next){
                    p->next->prev = t;
                }
                p->next = t;
            }  
        }

        int deleteLL(int pos){
            int x = -1;
            Node *p = head;
            if(pos<1 || pos>count()){
                return -1;
            }
            if(pos==1){
                head = head->next;
                if(head!=NULL){
                    head->prev = NULL;
                }
                x = p->data;
                delete p;
                return x;
            }
            else{
                for(int i=0;i<pos-1;i++){
                    p = p->next;
                }
                p->prev->next = p->next;
                if(p->next!=NULL){
                    p->next->prev = p->prev;
                }
                x = p->data;
                delete p;
                return x;
            }
        }
};

int main(){
    int A[] = {1,2,3,4,5,6,7,8};
    cout<<endl;
    DoublyLL p(A,8);
    p.display();
    cout<<endl;


    p.insert(7,12);
    p.display();
    cout<<endl;
    p.deleteLL(9);
    p.display();

    
    

    return 0;
}