/*
 * @Author: your name
 * @Date: 2020-09-21 21:00:31
 * @LastEditTime: 2021-01-05 00:04:18
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /区间合并/main.cpp
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

struct cmp{
    bool operator()(pair<int,int>& a, pair<int,int>& b){
        return a.first > b.first;
    }
};

int main(){
    int n;
    cin >> n;
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> q;
    for(int i = 0; i < n; ++i){
        int n1, n2;
        cin >> n1 >> n2;
        q.push(make_pair(n1,n2));
    }
    bool exist = true;
    while(q.size() != 1){
        pair<int,int> a = q.top();
        q.pop();
        pair<int,int> b = q.top();
        q.pop();
        if(b.first <= a.second){
            q.push(make_pair(a.first, max(a.second, b.second)));
        }else{
            exist = false;
            break;
        }
    }
    if(exist){
        cout << q.top().first << " " << q.top().second << endl;
    }else{
        cout << "no" << endl;
    }
    return 0;
}


/*
#include <stdlib.h>
#include <stdio.h>
#include <deque>
#include <algorithm>
using namespace std;
int n;
bool finded = false;
deque<pair<int,int>> q;

bool mycomp(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        q.push_back(make_pair(a, b));
    }
    sort(q.begin(), q.end(), mycomp);
    
    for(int i = 0; i < n; ++i){
        if(q.size() == 1){
            finded = true;
            break;
        }
        if(q.begin()->second>=(q.begin()+1)->first && q.begin()->second <= (q.begin()+1)->second){
            pair<int,int> newpair = make_pair(q.begin()->first, (q.begin()+1)->second);
            q.pop_front();
            q.pop_front();
            q.push_front(newpair);
        }else if(q.begin()->second>=(q.begin()+1)->first && q.begin()->second >= (q.begin()+1)->second){
            pair<int,int> newpair = make_pair(q.begin()->first, q.begin()->second);
            q.pop_front();
            q.pop_front();
            q.push_front(newpair);
        }
    }

    if(finded){
        printf("%d %d\n", q.front().first, q.front().second);
    }else{
        printf("no\n");
    }
    return 0;
}
*/