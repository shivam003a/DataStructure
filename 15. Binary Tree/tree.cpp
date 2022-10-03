#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node *lchild;
        int data;
        Node *rchild;
}*root=NULL;

class Queue{
    private:
        int size;
        int front;
        int rear;
        Node **Q;
    public:
        Queue(){
            size = 10;
            front = rear = 0;
            Q = new Node*[size];
        }
        Queue(int size){
            this->size = size;
            front = rear = 0;
            Q = new Node*[this->size];
        }
        int isFull(){
            if((rear+1)%size == front){
                return 1;
            }
            else return 0;
        }
        int isEmpty(){
            if(rear == front){
                return 1;
            }
            else return 0;
        }
        void enqueue(Node * x){
            if((rear+1)%size == front){
                cout<<"Queue is Full\n";
            }
            else{
                rear = (rear+1)%size;
                Q[rear] = x;
            }
        }
        Node * dequeue(){
            Node *x = NULL;
            if(rear == front){
                cout<<"Queue is Empty\n";
            }
            else{
                front = (front+1)%size;
                x = Q[front];
            }
            return x;
        }
        void display(){
            int i = front+1;
            do{
                cout<<Q[i]<<" ";
                i = (i+1)%size;
            }while(i!=(rear+1)%size);
            cout<<"\n";
        }

};

void create(){
    Queue q(100);
    Node *p,*t;

    int x;
    cout<<"Enter Root Element\n";
    cin>>x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);

    while(!q.isEmpty()){
        p = q.dequeue();
        cout<<"Enter left Element of "<<p->data<<endl;
        cin>>x;
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }

        cout<<"Enter right Element "<<p->data<<endl;
        cin>>x;
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void inorder(Node *p){
        if(p){
            inorder(p->lchild);
            cout<<p->data<<" ";
            inorder(p->rchild);
        }
}

void preorder(Node *p){
        if(p){
            cout<<p->data<<" ";
            preorder(p->lchild);
            preorder(p->rchild);
        }
}

void postorder(Node *p){
        if(p){
            postorder(p->lchild);
            postorder(p->rchild);
            cout<<p->data<<" ";
        }
}

int main(){
    create();

    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    

    return 0;
}