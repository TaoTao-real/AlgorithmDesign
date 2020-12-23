/*
 * @Author: your name
 * @Date: 2020-12-19 15:01:28
 * @LastEditTime: 2020-12-24 00:50:20
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

int board[8];
int rescount = 0;
void print_board(){
    cout << "No. " << rescount << endl;
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            if(board[j] == i){
                cout << 1 << " ";
            }else{
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

bool is_ok(int i, int j){
    for(int index = 0; index < i; ++index){
        if(board[index] == j) return false;
        if(abs(i-index) == abs(j - board[index])) return false;
    }
    return true;
}

void place(int i){
    if(i == 8){
        rescount++;
        print_board();
    }else{
        for(int j = 0; j < 8; ++j){
            board[i] = j;
            if(is_ok(i, j)){
                place(i+1);
            }
        }
    }
}

int main(){
    place(0);
    return 0;
}