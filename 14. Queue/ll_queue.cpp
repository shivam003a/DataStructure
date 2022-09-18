#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class Queue{
    private:
        Node *front;
        Node *rear;

    public:
        Queue(){
            front = NULL;
            rear = NULL;
        }
        void enqueue(int x){
            Node *t = new Node;
            if(t==NULL){
                cout<<"Queue Full"<<endl;
            }
            else{
                t->data = x;
                t->next = NULL;
                if(front==NULL){
                    front=rear=t;
                }
                else{
                    rear->next = t;
                    rear = t;
                }
            }
        }
        int dequeue(){
            int x = -1;
            if(front ==NULL){
                cout<<"Queue Empty"<<endl;
            }
            else{
                int p = front->data;
                Node *t = front;
                front = front->next;
                delete t;
            }
            return x;
        }
        void display(){
            Node *p = front;
            while(p){
                cout<<p->data<<" ";
                p = p->next;
            }
        }
};


int main(){
    Queue q;
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(8);
    q.enqueue(10);
    q.dequeue();
    q.dequeue();
    q.dequeue();


    q.display();
    

    return 0;
}