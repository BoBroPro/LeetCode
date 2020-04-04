#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    if (nums.size() < 3)
        return ans;

    sort(nums.begin(), nums.end());
    if (nums.front() > 0 || nums.back() < 0)
        return ans;
    if (nums.front() == 0 && nums.back() == 0)
        return vector<vector<int>>({{0,0,0}});
    
    set<vector<int>> set_tmp;
    for (int i = 0; i < (int)nums.size() - 1; ++i) {
        int l = i + 1;
        int r = nums.size() - 1;
        while (l < r) {
            if (nums[i] + nums[l] + nums[r] == 0) {
                set_tmp.insert({ nums[i],nums[l],nums[r] });
                ++l;
                --r;
            }
            else if (nums[i] + nums[l] + nums[r] < 0) {
                ++l;
            }
            else {
                --r;
            }
        }
    }
    ans.assign(set_tmp.begin(),set_tmp.end());
    return ans;
}

int main() {
    vector<int> nums{-1, 0, 1, 2, -1, -4 };
    vector<vector<int>> vec = threeSum(nums);
    for (auto i : vec) {
        for (auto j : i) {
            cout << j;
        }
        cout << endl;
    }
    getchar();
    return 0;
}