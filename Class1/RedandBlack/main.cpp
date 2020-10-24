/*
 * @Author: your name
 * @Date: 2020-09-22 14:54:06
 * @LastEditTime: 2020-09-22 15:14:20
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /RedandBlack/main.cpp
 */
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

const int MAXN = 25;
char matrix[MAXN][MAXN];
int w,h;
int res = 0;

void dfs(int x, int y, int w, int h){
    if(x <= 0 || x > w || y <= 0 || y > h) return;
    if(matrix[y][x] == '@' || matrix[y][x] == '#') return;
    matrix[y][x] = '@';
    ++res;
    dfs(x - 1, y, w, h);
    dfs(x + 1, y, w, h);
    dfs(x, y - 1, w, h);
    dfs(x, y + 1, w, h);
}

int main(){
    scanf("%d%d",&w,&h);
    while(w != 0 && h != 0){
        int x, y;
        for(int i = 1; i <= h; ++i){
            for(int j = 1; j <= w; ++j){
                cin >> matrix[i][j];
                if(matrix[i][j] == '@'){
                     x = j;
                     y = i;
                     matrix[i][j] = '.';
                }
            }
        }
        res = 0;
        dfs(x,y,w,h);
        printf("%d\n", res);
        scanf("%d%d", &w,&h);
    }
    return 0;
}