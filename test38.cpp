#include<iostream>
#include<sstream>
#include<strstream>
using namespace std;

string countAndSay(int n) {
    if(n==1){
        return "1";
    }
    string str = countAndSay(n-1);
    int cnt = 0;
    string ans;
    stringstream ss;
    string tmp;
    int l = 0; 
    int r = 0;
    for(r = 0; r < str.size();){
        if(str[l] == str[r]){
            cnt++;
            r++;
        }
        else{
            ss << cnt;
            ss >> tmp;
            ss.str();
            ss.clear();
            ans.append(tmp);
            ans.push_back(str[l]);
            l = r;
            cnt = 0;
        }
    }
    ss << cnt;
    ss >> tmp;
    ans.append(tmp);
    ans.push_back(str[l]);
    return ans;
}

int main(){
    cout <<  countAndSay(5)<<endl;
    getchar();
    return 0;
}