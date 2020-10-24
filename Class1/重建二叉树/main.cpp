/*
 * @Author: your name
 * @Date: 2020-09-22 15:22:59
 * @LastEditTime: 2020-09-22 15:56:38
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /重建二叉树/main.cpp
 */
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
string line;

class node{
public:
    char val;
    node* left;
    node* right;
    node(char Val, node* Left = NULL, node* Right = NULL): val(Val), left(Left), right(Right){}
};

void lrm(node* root){
    if(root == NULL) return;
    lrm(root->left);
    lrm(root->right);
    printf("%c", root->val);
}

node* buildTree(string& mlr, string& lmr){
    if(mlr == "" && lmr == "") return NULL;
    node* root = new node(mlr[0]); 
    if(mlr.size() == 1 && lmr.size() == 1){
        return root;
    }
    int pos = lmr.find(mlr[0]);
    string Lmlr = mlr.substr(1, pos);
    string Llmr = lmr.substr(0, pos);
    root->left = buildTree(Lmlr,Llmr);
    string Rmlr = mlr.substr(1 + pos, mlr.size() - pos - 1);
    string Rlmr = lmr.substr(pos + 1, mlr.size() - pos - 1);
    root->right = buildTree(Rmlr, Rlmr);
    return root;
}

node* root;

int main(){
    while(getline(cin, line)){
        string mlr, lmr;
        mlr = line.substr(0, line.size()/2);
        lmr = line.substr(line.size()/2 + 1, line.size()/2);
        root = buildTree(mlr, lmr);
        lrm(root);
        printf("\n");
    }
    return 0;
}