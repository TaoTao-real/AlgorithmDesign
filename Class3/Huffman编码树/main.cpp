/*
 * @Author: your name
 * @Date: 2020-10-16 22:33:42
 * @LastEditTime: 2021-01-09 15:04:36
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /projects/算法分析与复杂性理论/第三次作业/Huffman编码树/main.cpp
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        priority_queue<int, vector<int>, greater<int>> q;
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            q.push(x);
        }
        int res = 0;
        while(q.size() != 1){
            int a= q.top();
            q.pop();
            int b = q.top();
            q.pop();
            q.push(a+b);
            res+=a;
            res+=b;
        }
        cout << res << endl;
    }
    return 0;
}

/*
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <vector>
using namespace std;

class treeNode{
public:
    int val;
    treeNode* left, *right;
    treeNode(int _val, treeNode* _left=NULL, treeNode* _right=NULL): val(_val), left(_left), right(_right){}
    bool operator<(const treeNode* a){
        return this->val < a->val;
    }
    bool operator>(const treeNode* a){
        return this->val > a->val;
    }
};

struct cmp{
    bool operator()(const treeNode* a,const treeNode* b){
        return a->val > b->val;
    }
};

void dfs(treeNode* root, int& count, int depth){
    if(root->left == NULL && root->right == NULL){
        count+=depth*root->val;
        return;
    }
    if(root->left)
        dfs(root->left, count, depth+1);
    if(root->right)
        dfs(root->right, count, depth+1);
    return;
}

int pathlenSum(treeNode* root){
    int count = 0;
    dfs(root, count, 0);
    return count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        treeNode* root;
        int n;
        cin >> n;
        priority_queue<treeNode*, vector<treeNode*>, cmp> nums;
        while(n--){
            int num;
            cin >> num;
            nums.push(new treeNode(num));
        }
        while(!nums.empty()){
            treeNode* a = nums.top();
            nums.pop();
            if(nums.empty()){
                root = a;
            }else{
                treeNode* b = nums.top();
                nums.pop();
                nums.push(new treeNode(a->val+b->val, a, b));
            }
        }
        cout << pathlenSum(root) << endl;
    }
    return 0;
}
*/