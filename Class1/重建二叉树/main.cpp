/*
 * @Author: your name
 * @Date: 2020-09-22 15:22:59
 * @LastEditTime: 2021-01-05 15:55:40
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /重建二叉树/main.cpp
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class node{
public:
    char v;
    node* l;
    node* r;
    node(char _v, node* _l, node* _r): v(_v), l(_l), r(_r){}
};

void bfs(node* root){
    if(root == NULL) return;
    bfs(root->l);
    bfs(root->r);
    cout << root->v;
    return;
}

node* buildTree(string mlr, int s1, int e1, string lmr, int s2, int e2){
    if(s1 == e1){
        return new node(mlr[s1], NULL, NULL);
    }else if(s1 > e1 || s2 > e2){
        return NULL;
    }else{
        char root = mlr[s1];
        int mid = find(lmr.begin(), lmr.end(), root) - lmr.begin();
        int leftTreeSize = mid - s2;
        int righTreeSize = e2 - mid;
        return new node(root, buildTree(mlr, s1+1, s1 + leftTreeSize, lmr, s2, mid-1), buildTree(mlr, s1+leftTreeSize+1, e1, lmr, mid+1, e2));
    }
}

int main(){
    string mlr, lmr;
    while(cin >> mlr >> lmr){
        node* root = buildTree(mlr, 0, mlr.size()-1, lmr, 0, lmr.size()-1);
        bfs(root);
        cout << endl;
    }
    return 0;
}


/*
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
*/