/*
 * @Author: your name
 * @Date: 2020-11-11 13:34:52
 * @LastEditTime: 2020-11-11 16:14:28
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /projects/AlgorithmDesign/Class4/HumanGeneFunctions/main.cpp
 */
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
}