#include<bits/stdc++.h>
using namespace std;

class Diagonal{
    private:
        int n;
        int *A;
    public:
        Diagonal(int n){
            this->n = n;
            A = new int[this->n];
        }
        ~Diagonal(){
            delete []A;
        }
        void set(int i,int j,int val){
            if(i==j){
                A[i-1] = val;
            }
        }
        int get(int i,int j){
            if(i==j){
                return A[i-1];
            }
            else return 0;
        }
        void display(){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j){
                        cout<<A[i]<<" ";
                    }
                    else{
                        cout<<0<<" ";
                    }
                }
                cout<<endl;
            }
        }
};

int main(){

    Diagonal d(5);

    d.set(1,1,5);
    d.set(2,2,10);
    d.set(3,3,20);
    d.set(4,4,30);
    d.set(5,5,40);

    d.display();
    cout<<endl<<d.get(5,5);
    

    return 0;
}