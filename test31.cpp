#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

void swapVec(vector<int>& vec, int l, int r){
    int tmp;
    while(l<r){
        tmp = vec[l];
        vec[l] = vec[r];
        vec[r] = tmp; 
        l++;
        r--;
    }

}

void nextPermutation(vector<int>& nums) {
    if(nums.size() == 1){
        return;
    }
    int tmp, i, j;
    for(i = nums.size()-2; i >= 0; --i){
        if(nums[i] < nums[i+1]){
            for(j = i+1; j < nums.size(); ++j){
                if(nums[i] >= nums[j]){
                    tmp = nums[i];
                    nums[i] = nums[j-1];
                    nums[j-1] = tmp;
                    break;
                }  
            }
            if(j == nums.size()){
                tmp = nums[i];
                nums[i] = nums[nums.size()-1];
                nums[nums.size()-1] = tmp;
            }

            swapVec(nums,i+1, nums.size()-1);
            return;
        }
    }
    if(i == -1){
       swapVec(nums,0, nums.size()-1); 
    }
    return;
}



void print(const vector<int>& vec){
    for(auto i : vec){
        cout << i << " ";
    }
    cout <<endl;
}
int main(){
    vector<int> vec{7,3,4,3,2,1};
    nextPermutation(vec);
    print(vec);
    getchar();
    return 0;
    
}