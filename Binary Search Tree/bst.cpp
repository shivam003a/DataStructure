#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *lchild;
    int data;
    Node *rchild;
}*root=NULL;

void Insert(Node *p,int key){
    Node *r,*q;

    if(p==NULL){
        q = new Node;
        q->data = key;
        q->lchild=q->rchild = NULL;
        root = q;
    }
    else{
        while(p!=NULL){
            r = p;
            if(key<p->data){
                p = p->lchild;
            }
            else{
                p = p->rchild;
            }
        }
        q = new Node;
        q->data = key;
        q->lchild=q->rchild = NULL;

        if(key<r->data){
            r->lchild = q;
        }
        else{
            r->rchild = q;
        }
    }
}

void Inorder(Node *p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

Node *Search(Node *p,int key){

    while(p!=NULL){
        if(key==p->data){
            return p;
        }
        else if(key<p->data){
            p = p->lchild;
        }
        else{
            p = p->rchild;
        }
    }
    return NULL;
}

int main(){

    Insert(root,10);
    Insert(root,6);
    Insert(root,22);
    Insert(root,76);
    Insert(root,1);
    Insert(root,0);
    Insert(root,5);

    Inorder(root);
    cout<<endl;

    Node *x = Search(root,7);

    if(x!=NULL){
        cout<<"Key Found -> "<<x->data<<endl;
    }
    else{
        cout<<"Key Not Found"<<endl;
    }
    
    

    return 0;
}