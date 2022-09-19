#include<bits/stdc++.h>
using namespace std;

void insertionSort(int A[],int n){
    for(int i=1;i<n;i++){
        int x = A[i];
        int j = i-1;
        while(j>-1 && A[j]>x){
            A[j+1] = A[j];
            j--;
        }
    }
}

int main(){
    int A[] = {5,7,3,7,8,3,7,10,11,43};
    insertionSort(A,10);

    for(int i=0;i<10;i++){
        cout<<A[i]<<" ";
    }
    

    return 0;
}