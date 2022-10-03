#include<bits/stdc++.h>
using namespace std;

int pow(int x,int y){
    if(y==0){
        return 1;
    }
    return pow(x,y-1)*x;
}

int main(){
    cout<<pow(2,4)<<endl;
    

    return 0;
}