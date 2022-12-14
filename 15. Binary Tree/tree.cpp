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
};

void create(Queue q){
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

void iInorder(Node *p){
    stack<Node *> stk;

    while(!stk.empty() || p!=NULL){
        if(p!=NULL){
            stk.push(p);
            p = p->lchild;
        }
        else{
            p = stk.top();
            stk.pop();
            cout<<p->data<<" ";
            p = p->rchild;
        }
    }
}

void preorder(Node *p){
    if(p){
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void iPreorder(Node *p){
    stack<Node *> stk;

    while(!stk.empty() || p!=NULL){
        if(p!=NULL){
            cout<<p->data<<" ";
            stk.push(p);
            p = p->lchild;
        }
        else{
            p = stk.top();
            stk.pop();
            p = p->rchild;
        }
    }
}

void postorder(Node *p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

void levelOrder(Node *p){
    queue<Node *> q;

    cout<<p->data<<" ";
    q.push(p);

    while(!q.empty()){
        p = q.front();
        q.pop();
        if(p->lchild){
            cout<<p->lchild->data<<" ";
            q.push(p->lchild);
        }
        if(p->rchild){
            cout<<p->rchild->data<<" ";
            q.push(p->rchild);
        }
    }
}

int count(Node *p){
    int x,y;
    if(p){
        x = count(p->lchild);
        y = count(p->rchild);
        return x+y+1;
    }
    return 0;
}
int height(Node *p){
    int x,y;
    if(p){
        x = height(p->lchild);
        y = height(p->rchild);
        if(x>y){
            return x+1;
        }
        else{
            return y+1;
        }
    }
    return 0;
}
int leafNodes(Node *p){
    int x,y;
    if(p){
        x = height(p->lchild);
        y = height(p->rchild);
        if(p->lchild==NULL && p->rchild==NULL){
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
    return 0;
}


int main(){
    Queue q(100);
    create(q);

    inorder(root);
    cout<<endl;
    levelOrder(root);
    // preorder(root);
    cout<<endl;
    // postorder(root);
    // cout<<endl;
    cout<<count(root);
    cout<<endl;
    cout<<leafNodes(root);
    

    return 0;
}