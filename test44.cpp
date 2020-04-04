#include<iostream>
#include<vector>
using namespace std;

bool isMatch(string s, string p) {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int i = 0, j = 0, iStar = -1, jStar = -1, m = s.size(), n = p.size();
    while (i < m) {
        if (j < n && (s[i] == p[j] || p[j] == '?')) {
            ++i; ++j;
        } else if (j < n && p[j] == '*') {
            iStar = i;
            jStar = j++;
        } else if (iStar >= 0) {
            i = ++iStar;
            j = jStar + 1;
        } else return false;
    }
    while (j < n && p[j] == '*') ++j;
    return j == n;
}
int main(){
    string s = "abc";
    string p = "*b";
    cout << isMatch(s, p)<<endl;
    getchar();
}