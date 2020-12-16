/*
 * @Author: your name
 * @Date: 2020-12-16 19:17:44
 * @LastEditTime: 2020-12-16 19:25:46
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /projects/AlgorithmDesign/19期末/YogurtFactory/main.cpp
 */
#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long res = 0;
    int N, S, C, Y;
    cin >> N >> S;
    int minCost = 5005;
    for(int i = 0; i < N; ++i){
        cin >> C >> Y;
        minCost = min(minCost+S, C);
        res+=minCost*Y;
    }
    cout << res << endl;
    return 0;
}