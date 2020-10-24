/*
 * @Author: your name
 * @Date: 2020-09-21 18:55:10
 * @LastEditTime: 2020-09-21 19:53:24
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /projects/算法分析与复杂性理论/第一次作业/二维数组右上左下遍历/main.cpp
 */
#include <stdlib.h>
#include <stdio.h>
using namespace  std;
const int M = 100, N = 100;
int matrix[M][N];
int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            scanf("%d", &matrix[i][j]);
        }
    }
    for(int x = 0; x < n; ++x){
        for(int temp = x, y = 0; y < m && temp >=0; --temp, ++y){
            printf("%d\n", matrix[y][temp]);
        }
    }
    for(int y = 1; y < m; ++y){
        for(int temp = y, x = n - 1; x >= 0 && temp < m; --x, ++temp){
            printf("%d\n", matrix[temp][x]);
        }
    }
    return 0;
}