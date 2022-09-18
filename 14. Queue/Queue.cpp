#include<bits/stdc++.h>
using namespace std;

class Queue{
    private:
        int size;
        int front;
        int rear;
        int *Q;
    public:
        Queue(){
            size = 10;
            front = rear = -1;
            Q = new int[size];
        }
        Queue(int size){
            this->size = size;
            front = rear = -1;
            Q = new int[this->size];
        }
        int isFull(){
            if(rear == size-1){
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
        void enqueue(int x){
            if(rear == size-1){
                cout<<"Queue is Full\n";
            }
            else{
                rear++;
                Q[rear] = x;
            }
        }
        int dequeue(){
            int x = -1;
            if(rear == front){
                cout<<"Queue is Empty\n";
            }
            else{
                front++;
                x = Q[front];
            }
            return x;
        }
        void display(){
            for(int i=front+1;i<=rear;i++){
                cout<<Q[i]<<" ";
            }
        }

};

int main(){
    Queue q(3);
    q.enqueue(20);
    q.enqueue(67);
    q.enqueue(35);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<q.isEmpty()<<endl;
    q.enqueue(5);
    cout<<q.isEmpty();




    // q.display();

    return 0;
}