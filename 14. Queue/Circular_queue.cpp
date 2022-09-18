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
            front = rear = 0;
            Q = new int[size];
        }
        Queue(int size){
            this->size = size;
            front = rear = 0;
            Q = new int[this->size];
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
        void enqueue(int x){
            if((rear+1)%size == front){
                cout<<"Queue is Full\n";
            }
            else{
                rear = (rear+1)%size;
                Q[rear] = x;
            }
        }
        int dequeue(){
            int x = -1;
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

int main(){
    Queue q(4);
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