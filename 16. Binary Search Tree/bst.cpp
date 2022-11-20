#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};

class BinarySearchTree{
    public:
        Node *root;
        BinarySearchTree(){
            root = NULL;
        }
        void Insert(int x){
            Node *p=root,*q,*t;

            if(p==NULL){
                t = new Node;
                t->data = x;
                t->lchild = t->rchild = NULL;
                root = t;
                return;
            }
            while(p!=NULL){
                if(x==p->data){
                    return;
                }
                else if(x<p->data){
                    q = p;
                    p = p->lchild;
                }
                else if(x>p->data){
                    q = p;
                    p = p->rchild;
                }
            }

            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            if(t->data<q->data){
                q->lchild = t;
            }
            else{
                q->rchild = t;
            }
        }

        Node * rInsert(Node *p,int key){
            if(p==NULL){
                Node *temp;
                temp = new Node;
                temp->lchild = temp->rchild = NULL;
                temp->data = key;
                return temp;
            }
            if(key<p->data){
                p->lchild = rInsert(p->lchild,key);
            }
            else{
                p->rchild = rInsert(p->rchild,key);
            }
            return p;
        }

        void Inorder(Node *p){

            if(p!=NULL){
                Inorder(p->lchild);
                cout<<p->data<<" ";
                Inorder(p->rchild);
            }
        }

        Node* Search(int x){
            Node *p = root;

            while(p){
                if(x == p->data){
                    return p;
                }
                else if(x<p->data){
                    p = p->lchild;
                }
                else{
                    p = p->rchild;
                }
            }
            return NULL;
        }

        Node * rSearch(Node *p,int key){
            if(p==NULL){
                return NULL;
            }
            else{
                if(key==p->data){
                    return p;
                }
                else if(key<p->data){
                    return rSearch(p->lchild,key);
                }
                else{
                    return rSearch(p->rchild,key);
                }
            }
        }

        int height(Node* p){
            int x,y;
            if(p==NULL){
                return 0;
            }
            x = height(p->lchild);
            y = height(p->rchild);
            return x>y?x+1:y+1;
        }

        Node * inPred(Node *p){
            while(p->rchild!=NULL){
                p = p->rchild;
            }
            return p;
        }
        Node * inSucc(Node *p){
            while(p->lchild!=NULL){
                p = p->lchild;
            }
            return p;
        }

        Node * Delete(Node *p,int key){
            Node *q;

            if(p==NULL){
                return NULL;
            }
            if(p->rchild==NULL && p->lchild==NULL){
                if(p==root){
                    root = NULL;
                }
                delete p;
                return NULL;
            }

            if(key<p->data){
                p->lchild = Delete(p->lchild,key);
            }
            else if(key>p->data){
                p->rchild = Delete(p->rchild,key);
            }
            else{
                if(height(p->lchild)>height(p->rchild)){
                    q = inPred(p->lchild);
                    p->data = q->data;
                    p->lchild = Delete(p->lchild,q->data);
                }
                else{
                    q = inSucc(p->rchild);
                    p->data = q->data;
                    p->rchild = Delete(p->rchild,q->data);
                }
            }
            return p;
        }


};


int main(){
    BinarySearchTree bst;
    Node *temp;

    bst.root = bst.rInsert(bst.root,11);
    bst.rInsert(bst.root,3);
    bst.rInsert(bst.root,17);
    bst.rInsert(bst.root,1);
    bst.rInsert(bst.root,7);
    bst.rInsert(bst.root,15);
    bst.rInsert(bst.root,19);
    bst.rInsert(bst.root,5);
    bst.rInsert(bst.root,8);


    bst.Inorder(bst.root);
    cout<<endl;
    temp=bst.rSearch(bst.root,500);

    if(temp!=NULL){
        cout<<"Key Found\n";
    }
    else{
        cout<<"Key Not Found\n";
    }

    bst.Delete(bst.root,12);
    bst.Inorder(bst.root);
    

    return 0;
}