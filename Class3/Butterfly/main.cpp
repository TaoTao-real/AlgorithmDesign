/*
 * @Author: your name
 * @Date: 2020-10-13 17:45:15
 * @LastEditTime: 2020-10-15 22:46:06
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /算法分析与复杂性理论/第三次作业/Butterfly/main.cpp
 */
//使用了带偏移的并查集
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

const int MAXN = 1005;
int father[MAXN];
int relationship[MAXN];

int findfather(int i){
    if(father[i] != i){
        int ifather = father[i];
        father[i] = findfather(ifather);
        relationship[i] = relationship[i] == relationship[ifather]?0:1;
    }
    return father[i];
}
void unionSet(int a, int b, int c){
    int af = findfather(a), bf = findfather(b);
    father[bf] = af; 
    if(c == 0){
        relationship[bf] = relationship[a] == relationship[b]?0:1;
    }else{
        relationship[bf] = relationship[a] == relationship[b]?1:0;
    }
}

int main(){
    int n, m;
    while(cin >> n >> m){
        bool valid = true;
        for(int i = 0; i < n; ++i){
            father[i] = i;
            relationship[i] = 0;
        }
        while(m--){
            int a, b, c;
            cin >> a >> b >> c;
            int af = findfather(a), bf = findfather(b);
            if(af == bf){
                if((c == 0 && relationship[a] != relationship[b]) || (c == 1 && relationship[a] == relationship[b])){
                    valid = false;
                }
            }else{
                unionSet(a, b, c);
            }
        }
        if(valid){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}