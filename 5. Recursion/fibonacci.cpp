#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n<=1){
        return n;
    }
    return fib(n-2) + fib(n-1);
}

int iterativeFib(int n){
    if(n<=1){
        return n;
    }
    int t0=0,t1=1,s=0;
    for(int i=2;i<=n;i++){
        s = t0+t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int F[10];
int improvedFib(int n){
    if(n<=1){
        F[n] = n;
        return n;
    }
    else{
        if(F[n-2]==-1){
            F[n-2] = improvedFib(n-2);
        }
        if(F[n-1]==-1){
            F[n-1] = improvedFib(n-1);
        }
        F[n] = F[n-2] + F[n-1];
        return F[n];
    }

}

int main(){
    for(int i=0;i<10;i++){
        F[i] = -1;
    }

    cout<<improvedFib(10)<<endl;
    

    return 0;
}