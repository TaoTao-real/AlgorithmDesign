/*
 * @Author: your name
 * @Date: 2020-10-17 21:34:50
 * @LastEditTime: 2021-01-12 23:29:50
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /projects/算法分析与复杂性理论/第三次作业/Agri-Net/main.cpp
 */

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

class edge{
public:
    int w;
    int u, v;
    edge(int _w, int _u, int _v): w(_w), u(_u), v(_v){}
};

struct cmp{
    bool operator()(edge& a, edge& b){
        return a.w > b.w;
    }
};

int findfather(vector<int>& father, int a){
    if(father[a] == a){
        return a;
    }else{
        father[a] = findfather(father, father[a]);
        return father[a];
    }
}

void unionset(vector<int>& father, int a, int b){
    int fa = findfather(father, a);
    int fb = findfather(father, b);
    if(fa != fb){
        father[fb] = fa;
    }
}

int main(){
    int n;
    while(cin >> n){
        vector<int> father(n);
        for(int i = 0; i < n; ++i) father[i] = i;
        //vector<vector<int>> distance(n, vector<int>(n, 0));
        priority_queue<edge, vector<edge>, cmp> q;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                int distance;
                cin >> distance;
                if(j > i){
                    q.push(edge(distance, i, j));
                }
            }
        }
        int edgecount = 0;
        int res = 0;
        while(edgecount != n-1){
            edge e = q.top();
            if(findfather(father, e.u) != findfather(father, e.v)){
                unionset(father, e.u, e.v);
                res+=e.w;
                edgecount++;
            }
            q.pop();
        }
        cout << res << endl;
    }
    return 0;
}


/*
// Kruskal算法
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

const int MAXN = 105;
struct cmp
{
    bool operator()(pair<pair<int,int>, int>& a, pair<pair<int,int>,int>& b){
        return a.second>b.second;
    }
};

int father[MAXN];

int findfather(int i){
    if(father[i] == i){
        return father[i];
    }else{
        father[i] = findfather(father[i]);
        return father[i];
    }
}

void unionset(int a, int b){
    int af = findfather(a);
    int bf = findfather(b);
    if(af != bf){
        father[bf] = af;
    }
}

int main(){
    int n;
    while(cin >> n){
        //注意不要忘记堆的初始化，防止上一轮的数据污染
        priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, cmp> connections;
        for(int i = 1; i <= n; ++i) father[i] = i;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                int distance;
                cin >> distance;
                if(j>i)
                    connections.push(make_pair(make_pair(i, j), distance));
            }
        }
        int totalcost = 0;
        int pathcount = 0;
        while(pathcount != n-1){
            pair<pair<int,int>,int> shortestpath = connections.top();
            while(findfather(shortestpath.first.first) == findfather(shortestpath.first.second)){
                connections.pop();
                shortestpath = connections.top();
            }
            connections.pop();
            totalcost += shortestpath.second;
            pathcount++;
            unionset(shortestpath.first.first, shortestpath.first.second);
        }
        cout << totalcost << endl;
    }
    return 0;
}
*/
/*
//PRIM 算法
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

const int MAXN = 105;
struct cmp
{
    bool operator()(pair<pair<int,int>, int>& a, pair<pair<int,int>,int>& b){
        return a.second>b.second;
    }
};

int isconnected[MAXN] = {0};
int matrix[MAXN][MAXN] = {0};

int main(){
    int n;
    while(cin >> n){
        priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, cmp> crossBarConnections;
        memset(isconnected, 0, sizeof(isconnected));
        memset(matrix, 0, sizeof(matrix));
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                cin >> matrix[i][j];
            }
        }
        isconnected[1] = 1;
        int totalcost = 0;
        int isconnectedCount = 1;
        for(int j = 2; j <= n; ++j) crossBarConnections.push(make_pair(make_pair(1,j), matrix[1][j]));
        while(isconnectedCount != n){
            pair<pair<int,int>,int> shortestone = crossBarConnections.top();
            while(isconnected[shortestone.first.first] && isconnected[shortestone.first.second]){
                crossBarConnections.pop();
                shortestone = crossBarConnections.top();
            }
            crossBarConnections.pop();
            if(!isconnected[shortestone.first.first]){
                isconnected[shortestone.first.first]=1;
                for(int j = 1; j <= n; ++j){
                    crossBarConnections.push(make_pair(make_pair(shortestone.first.first, j), matrix[shortestone.first.first][j]));
                }
            }else{
                isconnected[shortestone.first.second]=1;
                for(int j = 1; j <= n; ++j){
                    crossBarConnections.push(make_pair(make_pair(shortestone.first.second, j), matrix[shortestone.first.second][j]));
                }                            
            }
            isconnectedCount++;
            totalcost+=shortestone.second;
        }
        cout << totalcost << endl;
    }
    return 0;
}
*/