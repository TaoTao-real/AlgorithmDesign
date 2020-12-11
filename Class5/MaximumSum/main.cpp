/*
 * @Author: your name
 * @Date: 2020-12-11 17:09:00
 * @LastEditTime: 2020-12-11 17:52:19
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /projects/AlgorithmDesign/Class5/MaximumSum/main.cpp
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
using namespace std;

int main(){
    int t;
    //cin >> t;
    scanf("%d", &t);
    getchar();
    while(t--){
        int n;
        //cin >> n;
        scanf("%d", &n);
        vector<int> nums(n);
        vector<int> f(n); // 以下标i为结尾的连续数组的最大和 f(i) = i == 0 ? nums[i] : max(nums[i], nums[i]+f(i-1))
        vector<int> g(n); // 以下标i为开头的连续数组的最大和 g(i) = i == n-1? nums[i] : max(nums[i], nums[i]+g(i+1))
        vector<int> G(n); // 在下标i和之后开头的连续数组的最大和 G(i) = i == n-1? g[i] : max(g[i], G[i+1])
        int maxRes = INT_MIN;
        for(int i = 0; i < n; ++i){
            //cin >> nums[i];
            scanf("%d", &nums[i]);
        }
        for(int i = 0; i < n; ++i){
            f[i] = i == 0 ? nums[i] : max(nums[i], nums[i]+f[i-1]);
        }
        for(int i = n-1; i >= 0; --i){
            g[i] = i == n-1 ? nums[i] : max(nums[i], nums[i]+g[i+1]);
            G[i] = i == n-1 ? g[i] : max(g[i], G[i+1]);
        }
        for(int i = 0; i < n-1; ++i){
            maxRes = max(maxRes, f[i]+ G[i+1]);
        }
        printf("%d\n", maxRes);
        //cout << maxRes << endl;
        getchar();
    }
    return 0;
}