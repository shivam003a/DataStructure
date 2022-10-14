#include<bits/stdc++.h>
using namespace std;

class Stack{
    private:
        int size;
        int top;
        int *S;

    public:
        Stack(int n){ 
            size = n;
            S = new int[size];
            top = -1;
        }
        void push(int x);
        int pop();
        int isEmpty();
        int stackTop();
};

void Stack::push(int x){
    if(top == size-1){
        cout<<"Stack Overflow";
    }
    else{
        top++;
        S[top] = x;
    }
}

int Stack::pop(){
    int x = -1;
    if(top==-1){
        cout<<"Stack Underflow";
    }
    else{
        x = S[top];
        top--;
    }
    return x;
}

int Stack::isEmpty(){
    if(top==-1){
        return 1;
    }
    return 0;
}

int Stack::stackTop(){
    if(!isEmpty())
        return S[top];
    return -1;
}

int isOperand(char x){
    if(x=='+' || x == '-' || x=='*' || x=='/'){
        return 0;
    }
    return 1;
}

int eval(string s,Stack st){
    int x1,x2,r;
    for(int i=0;i<s.length();i++){
        if(isOperand(s[i])){
            st.push(s[i]-'0');
        }
        else{
            x1 = st.pop();
            x2 = st.pop();
            switch (s[i]){
                case '+':
                    r = x2 + x1;
                    break;
                case '-':
                    r = x2-x1;
                    break;
                case '*':
                    r = x2*x1;
                    break;
                case '/':
                    r = x2/x1;
                    break;
            }
            st.push(r);
        }
    }
    return st.pop();
}

int main(){
    string s = "24*6-33/+";
    Stack st(s.length());
    cout<<eval(s,st)<<endl;

    return 0;
}