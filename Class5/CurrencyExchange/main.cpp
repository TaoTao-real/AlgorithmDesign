/*
 * @Author: your name
 * @Date: 2020-12-14 10:38:55
 * @LastEditTime: 2020-12-14 11:53:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /projects/AlgorithmDesign/Class5/CurrencyExchange/main.cpp
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdlib.h>

using namespace std;

double n, m, s, v;
int main(){
    cin >> n >> m >> s >> v;
    vector<vector<vector<double>>> link(n+1);
    vector<double> value(n+1,0);
    for(int i = 0; i < m; ++i){
        double A, B, RAB, CAB, RBA, CBA;
        cin >> A >> B >> RAB >> CAB >> RBA >> CBA;
        link[A].push_back(vector<double>{B, RAB, CAB});
        link[B].push_back(vector<double>{A, RBA, CBA});
    }
    deque<double> changed;
    value[s] = v;
    changed.push_back(s);
    for(int t = 0; t <= 2*n; ++t){
        int count = changed.size();
        while(count--){
            double node = changed.front();
            changed.pop_front();
            for(vector<double> l : link[int(node)]){
                double newvalue = (value[int(node)]-l[2])*l[1];
                if(value[int(l[0])] < newvalue && newvalue>0){
                    value[int(l[0])] = newvalue;
                    changed.push_back(l[0]);
                }
            }
            count = changed.size();
        }
    }
    if(value[int(s)]>v) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}