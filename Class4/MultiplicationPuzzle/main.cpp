/*
 * @Author: your name
 * @Date: 2020-11-11 16:37:43
 * @LastEditTime: 2021-01-13 20:09:52
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /projects/AlgorithmDesign/Class4/MultiplicationPuzzle/main.cpp
 */
#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <vector>
using namespace std;

int func(vector<vector<int>>& dp,vector<int>& nums, int start, int end){
    if(dp[start][end]!=INT_MAX) return dp[start][end];
    if(end-start == 1){
        return 0;
    }
    for(int i = start+1; i < end; ++i){
        int tmp = func(dp, nums, start, i) + func(dp, nums, i, end) + nums[start]*nums[i]*nums[end];
        dp[start][end] = min(dp[start][end], tmp);
    }
    return dp[start][end];
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }
    vector<vector<int>> dp(n, vector<int> (n, INT_MAX));
    cout << func(dp,nums, 0, n-1) << endl;
    return 0;
}

/*
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

long long minScore(int start, int end, vector<int>& cards, vector<vector<long long>>& mem){
    if(mem[start][end] != 0) return mem[start][end];
    if(end - start == 1){
        return 0;
    }
    long long minone = LLONG_MAX;
    for(int i = start+1; i < end; ++i){
        long long temp = minScore(start, i, cards, mem) + minScore(i, end, cards, mem) + cards[start]*cards[i]*cards[end];
        if(temp < minone) minone = temp;
    }
    mem[start][end] = minone;
    return minone;
}

int main(){
    int n;
    cin >> n;
    vector<int> cards;
    vector<vector<long long>> mem(n, vector<long long>(n,0));
    for(int i = 0;i < n; ++i){
        int card;
        cin >> card;
        cards.push_back(card);
    }
    cout << minScore(0, n-1, cards, mem) << endl;
    return 0;
}
*/