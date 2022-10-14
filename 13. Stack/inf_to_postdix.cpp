#include<bits/stdc++.h>
using namespace std;

class Stack{
    private:
        int size;
        int top;
        char *S;

    public:
        Stack(int n){ 
            size = n;
            S = new char[size];
            top = -1;
        }
        void push(int x);
        char pop();
        int isEmpty();
        char stackTop();
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

char Stack::pop(){
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

char Stack::stackTop(){
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

int precedence(char x){
    if(x=='+' || x=='-'){
        return 1;
    }
    else if(x=='*' || x=='/'){
        return 2;
    }
    return 0;
}


// it does not consider the associstivity of the expression and the paranthesis.
string infToPost(string inf,Stack st){
    string postfix = "";
    int i=0;
    while(i<inf.length()){
        if(isOperand(inf[i])){
            postfix += inf[i];
            i++;
        }
        else{
            if(precedence(inf[i])>precedence(st.stackTop())){
                st.push(inf[i++]);
            }
            else{
                postfix += st.pop();
            }
        }
    }
    while(!st.isEmpty()){
        postfix += st.pop();
    }
    return postfix;

}

int main(){
    string s = "a+b-c*d/2";
    Stack st(s.length());
    st.push('#');
    cout<<infToPost(s,st);

    return 0;
}