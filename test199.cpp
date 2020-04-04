#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> rightSideView(TreeNode* root) {
    vector<int> vec;
    if(!root){
        return vec;
    }

    queue<TreeNode*> que;
    TreeNode* tmp;
    que.push(root);
    
    while(!que.empty()){
        vec.push_back(que.back()->val);
        int n = que.size(); 
        
        for(int i = 0; i< n; ++i){
            tmp = que.front();
            que.pop();
            if(tmp->left){
                que.push(tmp->left);
            }
            if(tmp->right){
                que.push(tmp->right);
            }

        }
    }
    return vec;
}
TreeNode*  tree_bulid(vector<int> vec){
    if(!vec.size() || !vec[0]){
        return nullptr;
    }
    queue<TreeNode*> que;
    TreeNode* root = new TreeNode(vec[0]);
    que.push(root);
    int i = 1;
    while(que.size() ){
        if(i< vec.size()){
            if(vec[i]!=0){
                que.front()->left = new TreeNode(vec[i]);
                que.push(que.front()->left);

            }
            ++i; 
        }
        if(i<vec.size()){
            if(vec[i]!=0){
                que.front()->right = new TreeNode(vec[i]);
                que.push(que.front()->right);
            }
            ++i;
        }
        que.pop();    
    }
    return root;
}

void printTree(const TreeNode* root){
    if(!root){
        return;
    }
    const TreeNode* p = root;
    queue<const TreeNode*> que;
    que.push(p);
    while(!que.empty()){
        cout << que.front()->val;
        if(que.front()->left){
            que.push(que.front()->left);
        }
        if(que.front()->right){
            que.push(que.front()->right);
        }
        que.pop();
    }
    cout <<endl;

}
void print(const vector<int> vec){
    for (auto i : vec){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    vector<int> vec{1,2,3,0,5,0,4};
    vector<int> ans;
    TreeNode* root =  tree_bulid(vec);
    printTree(root);
    ans = rightSideView(root) ;
    print(ans);

    getchar();
    return 0;

}
