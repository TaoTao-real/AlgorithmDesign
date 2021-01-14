/*
 * @Author: your name
 * @Date: 2020-11-11 13:34:52
 * @LastEditTime: 2021-01-14 11:27:55
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /projects/AlgorithmDesign/Class4/HumanGeneFunctions/main.cpp
 */

#include<iostream>
#include<map>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits.h>
using namespace std;

int main(){
    map<char,int> exchange;
    exchange['A'] = 0;
    exchange['C'] = 1;
    exchange['G'] = 2;
    exchange['T'] = 3;
    vector<vector<int>> value = {{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,0}};
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n;
        vector<int> gen1;
        gen1.push_back(-1);
        for(int i = 0; i < n; ++i){
            char tmp;
            cin >> tmp;
            gen1.push_back(exchange[tmp]);
        }
        cin >> m;
        vector<int> gen2;
        gen2.push_back(-1);
        for(int i = 0; i < m; ++i){
            char tmp;
            cin >> tmp;
            gen2.push_back(exchange[tmp]);
        }
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; ++i) dp[i][0] = dp[i-1][0] + value[gen1[i]][4];
        for(int j = 1; j <= m; ++j) dp[0][j] = dp[0][j-1] + value[4][gen2[j]];
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                int maxvalue = INT_MIN;
                maxvalue = max(maxvalue, dp[i-1][j-1]+value[gen1[i]][gen2[j]]);
                maxvalue = max(maxvalue, dp[i-1][j]+value[gen1[i]][4]);
                maxvalue = max(maxvalue, dp[i][j-1]+value[4][gen2[j]]);
                dp[i][j] = maxvalue;
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}

/*
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

vector<vector<int>> values = {{5,-1,-2,-1, -3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,0}};

int maxGenMatch(int start1, int start2, vector<int>& gen1, vector<int>& gen2, vector<vector<int>>& mem){
    if(start1 == gen1.size() && start2 == gen2.size()) return 0;
    if(mem[start1][start2] != 0) return mem[start1][start2];
    int res = -INT_MAX;
    if(start1 < gen1.size() && start2 < gen2.size()){
        int temp = maxGenMatch(start1+1, start2+1, gen1,gen2,mem)+values[gen1[start1]][gen2[start2]];
        if(temp > res) res = temp;
    }
    if(start1 < gen1.size()){
        int temp = maxGenMatch(start1+1, start2, gen1, gen2, mem)+values[gen1[start1]][4];
        if(temp > res) res = temp;
    }
    if(start2 < gen2.size()){
        int temp = maxGenMatch(start1, start2+1, gen1, gen2, mem)+values[4][gen2[start2]];
        if(temp > res) res = temp;
    }
    mem[start1][start2] = res;
    return res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        vector<vector<int>> mem(105,vector<int>(105,0));
        int len1, len2;
        vector<int> gen1, gen2;
        cin >> len1;
        for(int i = 0; i < len1; i++){
            char gen;
            cin >> gen;
            switch (gen)
            {
            case 'A':
                gen1.push_back(0);                
                break;
            case 'C':
                gen1.push_back(1);
                break;
            case 'G':
                gen1.push_back(2);
                break;
            case 'T':
                gen1.push_back(3);
                break;
            }
        }   
        cin >> len2;
        for(int i = 0; i < len2; i++){
            char gen;
            cin >> gen; 
            switch (gen)
            {
            case 'A':
                gen2.push_back(0);                
                break;
            case 'C':
                gen2.push_back(1);
                break;
            case 'G':
                gen2.push_back(2);
                break;
            case 'T':
                gen2.push_back(3);
                break;
            }
        }
        cout << maxGenMatch(0,0,gen1,gen2,mem) << endl;
    }
    return 0;
}*/