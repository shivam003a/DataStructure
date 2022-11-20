#include<bits/stdc++.h>
using namespace std;

int rec(int num){
    if(num==0){
        return 1;
    }
    return num*rec(num-1);
}

int main(){
    cout<<rec(10000000);
    

    return 0;
}