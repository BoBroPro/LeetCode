#include<iostream>
#include<stack>
using namespace std;


bool isMatched(char c1, char c2){

    if(c1 == '(' && c2 == ')' ||
        c1 == '[' && c2 == ']' ||
        c1 == '{' && c2 == '}'    
        )
        return true;
    else
         return false;
    
}

bool isValid(string s) {
    if(s.size() == 0){
        return true;
    }
    
    stack<char> stack_ch;
    for(int i = 0; i< s.size(); ++i){
        if(stack_ch.size() == 0){
            stack_ch.push(s[i]);
            continue;
        }
        if(isMatched(stack_ch.top(), s[i])){
            stack_ch.pop();
        }
        else {
            stack_ch.push(s[i]);
        }
    }
    if(stack_ch.empty()){
        return true;
    }
    else
    {
        return false;
    }
}


int main(){
    string s = "()";
    cout << isValid(s);
    getchar();
    return 0;
}