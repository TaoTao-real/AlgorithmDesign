/*
 * @Author: your name
 * @Date: 2020-09-22 12:34:45
 * @LastEditTime: 2020-10-02 15:23:47
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /去除C程序中的注释/main.cpp
 */
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

bool iscomment = false;
bool isstring = false;
int main(){
    string program;
    string line;
    while(getline(cin, line)){
        program += line+'\n';
    }
    int i = 0;
    while(i <= program.size() - 1){
        while(!iscomment && !isstring && i < program.size()-1){
            if(program[i] == '/' && program[i+1] == '*'){
                iscomment = true;
                i+=2;
            }
            else if(program[i] != '\\' && program[i+1] == '"'){
                isstring = true;
                cout << program[i] << program[i+1];
                i+=2;
            }else{
                cout << program[i++];
            }
        }
        while(iscomment && i < program.size()-1){
            if(program[i] == '*' && program[i+1] == '/'){
                iscomment = false;
                i+=2;
            }else{
                i++;
            }
        }
        while(isstring && i < program.size()-1){
            if(program[i] == '\\' && program[i+1]=='"'){
                cout << program[i] << program[i+1];
                i+=2;
            }
            else if(program[i] == '"'){
                isstring = false;
                cout << program[i++];
            }
            else{
                cout << program[i++];
            }
        }
    }
    return 0;
}