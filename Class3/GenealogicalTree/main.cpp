/*
 * @Author: your name
 * @Date: 2020-10-15 22:47:09
 * @LastEditTime: 2020-10-16 20:37:07
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /projects/算法分析与复杂性理论/第三次作业/Genealogical tree/main.cpp
 */

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 105;
vector<vector<int> > children;
int indegree[MAXN] = {0};
deque<int> q;
int main(){
    vector<int> space;
    children.push_back(space);
    int n;
    cin >> n;
    int t = n;
    while(t--){
        vector<int> ithchildren;
        int child;
        cin >> child;
        while(child){
            ithchildren.push_back(child);
            indegree[child]++;
            cin >> child;
        }
        children.push_back(ithchildren);
    }

    for(int i = 1; i <= n; ++i){
        if(indegree[i] == 0) q.push_back(i);
    }
    while(!q.empty()){
        for(int i: children[q.front()]){
            indegree[i]--;
            if(indegree[i] == 0) q.push_back(i);
        }
        cout << q.front() << " ";
        q.pop_front();
    }
    cout << endl;
    return 0;
}
