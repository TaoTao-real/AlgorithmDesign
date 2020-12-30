/*
 * @Author: your name
 * @Date: 2020-12-30 09:37:35
 * @LastEditTime: 2020-12-30 10:16:20
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /projects/AlgorithmDesign/19期末/Maximum sum/main.cpp
 */
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n,0);
        for(int i = 0; i < n; ++i){
            cin >> nums[i];
        }
        vector<int> f(n, 0);
        f[0] =  nums[0];
        vector<int> g(n, 0);
        g[n-1] = nums[n-1];
        vector<int> G(n, 0);
        G[n-1] = g[n-1];
        for(int i = 1; i < n; ++i){
            f[i] = max(nums[i], nums[i] + f[i-1]);
        }
        int maxg = G[n-1];
        for(int i = n-2; i >=0; --i){
            g[i] = max(nums[i], nums[i] + g[i+1]);
            maxg = max(maxg, g[i]);
            G[i] = maxg;
        }
        int maxsum = INT_MIN;
        for(int i = 0; i < n-1; ++i){
            maxsum = max(maxsum, f[i] + G[i+1]);
        }
        cout << maxsum << endl;
    }
    return 0;
}