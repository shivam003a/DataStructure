#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int A[],int n){
    for(int i=0;i<n-1;i++){
        int j,k;
        for(j=k=i;j<n;j++){
            if(A[j]<A[k]){
                k = j;
            }
        }
        swap(&A[i],&A[k]);
    }
}
int main(){
    int A[] = {2,6,4,7,8,3,1,5,7,10};
    selectionSort(A,10);

    for(auto i : A){
        cout<<i<<" ";
    }
    

    return 0;
}