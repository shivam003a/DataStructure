#include<bits/stdc++.h>
using namespace std;

int fact(int x){
    if(x==0){
        return 1;
    }
    return fact(x-1)*x;
}

int iterativeFact(int x){
    int fact = 1;
    while(x>0){
        fact *= x;
        x--;
    }
    return fact;
}

int main(){
    cout<<"Factorial using Loops "<<iterativeFact(5)<<endl;
    cout<<"Factorial using Recursion "<<fact(5)<<endl;


    return 0;
}