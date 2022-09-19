#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


// O(n^2) and if is already sorted then O(n)
void bubbleSort(int A[] ,int n){
    int flag;
    for(int i=0;i<n-1;i++){
        flag=0;
        for(int j=0;j<n-i-1;j++){
            if(A[j]>A[j+1]){
                swap(&A[j],&A[j+1]);
                flag=1;
            }
        }
        if(flag==0){
            cout<<"already sorted\n";
            break;
        }
    }
}

int main(){
    int A[10] = {1,3,4,5,6};
    bubbleSort(A,5);

    for(int i=0;i<5;i++){
        cout<<A[i]<<" ";
    }    

    return 0;
}