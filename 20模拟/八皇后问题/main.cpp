/*
 * @Author: your name
 * @Date: 2020-12-19 15:01:28
 * @LastEditTime: 2020-12-19 15:10:16
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /projects/AlgorithmDesign/20模拟/八皇后问题/main.cpp
 */
#include <iostream>
#include <vector>
#include <string.h>
#include <limits.h>
#include <string>

using namespace std;

bool isvalid(vector<vector<int>>& pos){
    for(int i = 0; i < 8; ++i){
        for(int j = i; j < 8; ++j){
            if(pos[i][1] == pos[j][1] || abs(pos[i][0]-pos[j][0]) == abs(pos[i][1]-pos[j][1])){
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<vector<int>> pos(8, vector<int>(2,0));
    for(int i = 0; i < 8; ++i){
        pos[i][0] = i;
    }
    traceback(pos, )
}