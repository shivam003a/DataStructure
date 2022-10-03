#include<bits/stdc++.h>
using namespace std;

int sum(int x){
    if(x>0){
        return sum(x-1) + x;
    }
    return 0;
}

int main(){
    cout<<sum(5);
 
    return 0;
}