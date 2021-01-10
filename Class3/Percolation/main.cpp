/*
 * @Author: your name
 * @Date: 2020-10-13 13:26:26
 * @LastEditTime: 2021-01-09 14:47:45
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /算法分析与复杂性理论/第三次作业/Percolation/main.cpp
 */

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

pair<int,int> findfather(vector<vector<pair<int,int>>>& father, pair<int,int> a){
    if(father[a.first][a.second] == a){
        return a;
    }else{
        father[a.first][a.second] = findfather(father, father[a.first][a.second]);
        return father[a.first][a.second];
    }
}

void unionset(vector<vector<pair<int,int>>>& father, pair<int,int> a, pair<int,int> b){
    pair<int,int> fa = findfather(father, a);
    pair<int,int> fb = findfather(father, b);
    if(fa != fb){
        father[fb.first][fb.second] = fa;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int isPercolation = false;
        int stepcount = 0;
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int,int>>> father(n+2, vector<pair<int,int>> (n+2));
        vector<vector<int>> isopen(n+2, vector<int> (n+2, 0));
        for(int i = 0; i < n+2; ++i){
            for(int j = 0; j < n+2; ++j){
                if(i == 0){
                    father[i][j] = make_pair(0, 0);
                    isopen[i][j] = 1;
                }else if(i == n+1){
                    father[i][j] = make_pair(n+1, 0);
                    isopen[i][j] = 1;
                }else{
                    father[i][j] = make_pair(i, j);
                }
            }
        }
        while(m--){
            int y, x;
            cin >> y >> x;
            if(isPercolation == false){
                stepcount++;
                isopen[y][x] = 1;
                if(isopen[y-1][x]){
                    unionset(father, make_pair(y, x), make_pair(y-1, x));
                }
                if(isopen[y+1][x]){
                    unionset(father, make_pair(y, x), make_pair(y+1, x));
                }
                if(isopen[y][x-1]){
                    unionset(father, make_pair(y, x), make_pair(y, x-1));
                }
                if(isopen[y][x+1]){
                    unionset(father, make_pair(y, x), make_pair(y, x+1));
                }
                if(findfather(father, make_pair(0,0)) == findfather(father, make_pair(n+1, 0))){
                    isPercolation = true;
                }
            }
        }
        if(isPercolation){
            cout << stepcount<< endl;
        }else {
            cout << -1 << endl;
        }
        return 0;
    }
}

/*
//⚠️横纵坐标都从1开始。。。卡了好久
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;
const int MAXN = 1005;
pair<int,int> father[MAXN][MAXN];
int isopen[MAXN][MAXN];

pair<int, int> findfather(int i, int j){
    if(father[i][j] == make_pair(i,j)){
        return father[i][j];
    }else{
        father[i][j] = findfather(father[i][j].first, father[i][j].second);
        return father[i][j];
    }
}

void unionset(int ai, int aj, int bi, int bj){
    pair<int,int> af = findfather(ai, aj);
    pair<int,int> bf = findfather(bi, bj);
    if(af != bf){
        father[bf.first][bf.second] = af;
    }
}

int main(){
    int t, n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        int stepcount = 0;
        bool isPercolation = false;                
        memset(isopen,0,sizeof(isopen));
        for(int i = 1; i <= n;++i){
            father[0][i] = make_pair(0,1);
            isopen[0][i] = 1;
            father[n+1][i] = make_pair(n+1, 1);
            isopen[n+1][i] = 1;
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                father[i][j] = make_pair(i,j);
            }
        }
        
        while(m--){
            int i,j;
            cin >> i >> j;
            if(isPercolation == false){
                stepcount++;
                isopen[i][j] = 1;
                if(isopen[i-1][j]) unionset(i,j,i-1,j);
                if(isopen[i+1][j]) unionset(i,j,i+1,j);
                if(isopen[i][j-1]) unionset(i,j,i,j-1);
                if(isopen[i][j+1]) unionset(i,j,i,j+1);
                if(findfather(0,1) == findfather(n+1,1)) isPercolation = true;
            }
        }
        if(isPercolation){
            cout << stepcount << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}

*/
/* 会超时
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
const int MAXN = 1005;
int isopen[MAXN][MAXN];
int isvisited[MAXN][MAXN];
bool dfs(int n, int starti, int startj, int endi, int endj){
    if(starti == endi && startj == endj) return true;
    if(starti < 0 || startj <0 || starti > n+1 || startj > n+1 || isopen[starti][startj] == 0 || isvisited[starti][startj] == 1) return false;
    bool findpath = false;
    isvisited[starti][startj] = 1;
    findpath = dfs(n, starti - 1, startj, endi, endj) || dfs(n, starti+1, startj, endi, endj) || dfs(n, starti, startj - 1, endi, endj) || dfs(n, starti, startj + 1, endi, endj);
    isvisited[starti][startj] = 0;
    return findpath;
}

int t, n, m;
int main(){
    scanf("%d", &t);
    memset(isvisited, 0, sizeof(isvisited));
    while(t--){
        memset(isopen, 0, sizeof(isopen));
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i){
            isopen[0][i] = 1;
            isopen[n+1][i] = 1;
        }
        int i, j, k = 0;
        bool isPercolation = false;
        int res;
        bool begintest = false;
        while(k != m){
            k++;
            scanf("%d%d", &i,&j);
            if(!isPercolation){
                isopen[i][j] = 1;
                if(i == n) begintest = true;
                if(begintest){
                    isPercolation = dfs(n,0,0,n+1,0);
                    if(isPercolation){
                        res = k;    
                    }
                }
            }
            begintest = false;
        }
        if(!isPercolation) res = -1;
        printf("%d\n", res);
    }
    return 0;
}
*/