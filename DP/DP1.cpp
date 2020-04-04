#include<iostream>
#include<vector>
using namespace std;

int main(){
    int arr[7] = {1,20,4,1,7,8,3};
    vector<int> ans(7,-1);
    ans[0] = 1;
    ans[1] = 20;
    for(int i = 0; i < 7; ++i){
        if(ans[i] == -1){
            ans[i] = (arr[i] + ans[i-2] > ans[i-1] ? arr[i] + ans[i-2]: ans[i-1]); 
        }
    }
    cout << ans[6]<<endl;
    
    return 0;
}