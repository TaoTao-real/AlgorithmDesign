/*
 * @Author: your name
 * @Date: 2020-12-15 17:29:14
 * @LastEditTime: 2020-12-15 17:55:38
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /projects/AlgorithmDesign/Class5/CheckinganAlibi/main.cpp
 */
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <algorithm>
#include <limits.h>
using namespace std;

int main(){
    int F,P,C,M;
    cin >> F >> P >> C >> M;
    vector<vector<vector<int>>> G(F+1);
    vector<int> cows(C+1);
    vector<int> distance(F+1, INT_MAX);
    deque<int> changed;
    for(int i = 0; i < P; ++i){
        int A, B, D;
        cin >> A >> B >> D;
        G[A].push_back(vector<int>{B,D});
        G[B].push_back(vector<int>{A,D});
    }
    for(int i = 1; i <= C; ++i){
        cin >> cows[i];
    }
    distance[1] = 0;
    changed.push_back(1);
    int levelcount = 1;
    for(int t = 0; t < F+1; ++t){
        while(!changed.empty()){
            while(levelcount--){
                int field = changed.front();
                changed.pop_front();
                for(vector<int> v : G[field]){
                    int newdis = distance[field] + v[1];
                    if(newdis < distance[v[0]]){
                        distance[v[0]] = newdis;
                        changed.push_back(v[0]);
                    }
                }
            }
            levelcount = changed.size();
        }
    }
    vector<int> suspected;
    for(int i = 1; i <= C; ++i){
        if(distance[cows[i]] <= M){
            suspected.push_back(i);
        }
    }
    cout << suspected.size() << endl;
    for(int i = 0; i < suspected.size(); ++i){
        cout << suspected[i] << endl;
    }
    return 0;
}