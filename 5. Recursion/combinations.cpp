#include<bits/stdc++.h>
using namespace std;

int fact(int x){
    if(x==0){
        return 1;
    }
    return fact(x-1)*x;
}

int nCr(int n,int r){
    int num = fact(n);
    int den = fact(r)*fact(n-r);

    return num/den;
}

// using pascal's triangle
int NCR(int n,int r){

    if(r==0 || r==n){
        return 1;
    }
    return NCR(n-1,r-1) + NCR(n-1,r);
}

int main(){
    cout<<NCR(5,1);

    return 0;
}