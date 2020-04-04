#include<iostream>
#include<string>
#include<vector>
using namespace std;

string convert(string s, int numRows){
    string ans;
    int slen = s.size();
    int block  = (numRows-1)*2;
    if(numRows == 1){
        block = 1;
    }
    for(int i=0; i < numRows; i++){
        for(int j =0; block*j < slen; ++j){
            if(i == 0){
                if(block*j  < slen)
                    ans.push_back(s[block*j]);
            }
            else if(i < numRows-1){
                if( block*j + i < slen ){
                     ans.push_back(s[ block*j + i]);
                }
                if((numRows-1)*(2*j+1)*2- (block*j + i) < slen){
                    ans.push_back(s[(numRows-1)*(2*j+1)*2- (block*j + i)]);
                }
            }
            else {
                if(block*j + numRows -1 < slen)
                    ans.push_back(s[block*j + numRows -1]);
            }
        }
     
    }

    return ans;
}

string convert2(string s, int numRows){
    if(numRows == 1){
        return s;
    }
    string ans;
    vector<string> str_row(numRows);
    int i = 0;
    int flag = -1;
    for(char c : s){
        str_row[i] += c;
        if(i == 0 || i == numRows-1){
            flag = -flag;
        }
        i+=flag;  
    }
    for(auto ss : str_row){
        ans += ss;
    }
    return ans;
}

int main(){
    string s = "LEETCODEISHIRING";
    string ans = convert2(s,4);
    cout << ans<<endl;
    getchar();
}