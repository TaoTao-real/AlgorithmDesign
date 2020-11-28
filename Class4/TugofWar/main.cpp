/*
 * @Author: your name
 * @Date: 2020-11-11 18:34:55
 * @LastEditTime: 2020-11-24 15:57:31
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /projects/AlgorithmDesign/Class4/TugofWar/main.cpp
 */
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <limits>
#include <vector>
using namespace std;

const int MAXN = 105;
const int MAXW = 455;

int mem[MAXN/2][MAXN*MAXW/2] = {0};
int weight[MAXN] = {0};
int n, weightSum = 0;
vector<int> members;

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int temp;
        cin >> temp;
        weightSum += temp;
        weight[i] = temp;
    }
    int halfweightSum = weightSum/2;
    int halfn;
    if(n%2)
        halfn = (n/2)+1;
    else
        halfn = n/2;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= halfn; ++j){
            for(int k = 0; k <= halfweightSum; ++k){
                if(k < weight[i]){
                    mem[j][k] = mem[j][k];
                }else{
                    mem[j][k] = max(mem[j][k], mem[j-1][k-weight[i]]+weight[i]);
                }
            }
        }
    }
    int maxweight = 0;
    for(int i = halfn; i >= 1; --i){
        for(int j = halfweightSum; j >= 0; --j){
            if(mem[i][j] > maxweight) maxweight = mem[i][j];
        }
    }
    cout << min(maxweight, weightSum - maxweight) << " " << max(maxweight, weightSum - maxweight) << endl;
    return 0;
}