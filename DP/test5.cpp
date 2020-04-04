#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string str = "acbcabbdadbba";
    int l = 0;
    int r = 0;
    int i = 0;
    int len = 0;
    int start = 0;
    for(i = 0; i<str.length(); ++i){
    // when the substr.length is odd number
        for(l = r = i; l >= 0 && r < str.length() && str[l] == str[r]; --l, ++r){
            if(r-l+1 > len){
                start = l;
                len = r-l+1;
            }
        }
        
    // when the substr.length is even number
        for(l = i, r = i+1; l >= 0 && r < str.length() && str[l] == str[r]; --l, ++r ){
            len = len > r-l-1 ? len : r-l-1;
            if(r-l+1 > len){
                start = l;
                len = r-l+1;
            }
        } 

    }
    
    string substr = str.substr(start,len);
    cout << substr<<endl;

    return 0;
}