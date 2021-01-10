/*
 * @Author: your name
 * @Date: 2020-10-17 16:34:42
 * @LastEditTime: 2021-01-09 16:46:02
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /projects/算法分析与复杂性理论/第三次作业/RadarInstallation/main.cpp
 */

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(pair<double, double> a, pair<double, double> b){
        return a.first > b.first;
    }
};

int main(){
    int n;
    double d;
    int t = 0;
    cin >> n >> d;
    while(n!= 0 && d != 0){
        bool isvalid = true;
        int radarCount = 0;
        priority_queue<pair<double, double>, vector<pair<double,double>>, cmp> q;
        double x, y;
        for(int i = 0; i < n; ++i){
            cin >> x >> y;
            if(y < 0 || y > d) isvalid = false;
            if(isvalid){
                double z = pow(d*d - y*y, 0.5);
                q.push(make_pair(x-z, x+z));
            }
        }
        if(isvalid){
            while(q.size() > 1){
                pair<double, double> a = q.top();
                q.pop();
                pair<double, double> b = q.top();
                q.pop();

                if(a.second < b.first){
                    radarCount++;
                    q.push(b);
                }else{
                    q.push(make_pair(b.first, min(a.second, b.second)));
                }
            }
            cout << "Case " << ++t << ": "  << radarCount+1 << endl;
        }else{
            cout << "Case " << ++t << ": " << -1 << endl;
        }

        cin >> n >> d;
    }
    return 0;
}
/*

// 区间按照尾部排序，找出最大的独立子集合，独立子集合中区间的个数就是雷达站的个数，
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

struct cmp{
    bool operator()(pair<double,double>& a, pair<double,double>& b){
        return a.second > b.second;
    }
};
int main(){
    int n;
    double d;
    int t = 0;
    while(cin >> n >> d){
        bool invalidIsland = false;    
        if(n == 0 && d == 0) break;
        t++;
        int radarCount = 0;
        priority_queue<pair<double,double>, vector<pair<double,double>>, cmp> radarArea;
        while(n--){
            double x, y;
            cin >> x >> y;
            if(y < 0 || y>d) invalidIsland = true; 
            if(d >= y && invalidIsland == false)
                radarArea.push(make_pair(x-pow(d*d-y*y,0.5), x+pow(d*d-y*y,0.5)));
        }
        if(invalidIsland){
            radarCount = -1;
        }else{
            radarCount = 1;
            double lastIntervalEnd = radarArea.top().second;
            radarArea.pop();
            while(!radarArea.empty()){
                pair<double,double> radarinterval = radarArea.top();
                radarArea.pop();
                if(radarinterval.first>lastIntervalEnd){
                    radarCount++;
                    lastIntervalEnd = radarinterval.second;
                }
            }
        }
        cout << "Case " << t << ": " << radarCount << endl;
    }
    return 0;
}
*/
/*
// 区间合并，按照区间头部排序之后，找到重叠的区间
// OMG卡了半天，各种测试数据都是对的，问题出在坐标应该用double而不是int来记录
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

struct cmp{
    bool operator()(pair<double,double>& a, pair<double,double>& b){
        return a.first > b.first;
    }
};

void unionRadar(priority_queue<pair<double,double>, vector<pair<double,double>>, cmp>& radarArea, int& radarCount){
    if(radarArea.size() == 1){
        radarCount++;
        radarArea.pop();
        return;
    }
    pair<double,double> a = radarArea.top();
    radarArea.pop();
    pair<double,double> b = radarArea.top();
    radarArea.pop();
    if(a.second >= b.first){
        if(a.second <= b.second){
            radarArea.push(make_pair(b.first, a.second));
        }else{
            radarArea.push(b);
        }
    }else{
        radarArea.push(b);
        radarCount++;
    }
    unionRadar(radarArea, radarCount);
}

int main(){
    int n;
    double d;
    int t = 0;
    while(cin >> n >> d){
        bool invalidIsland = false;    
        if(n == 0 && d == 0) break;
        t++;
        int radarCount = 0;
        priority_queue<pair<double,double>, vector<pair<double,double>>, cmp> radarArea;
        while(n--){
            double x, y;
            cin >> x >> y;
            if(y < 0 || y>d) invalidIsland = true; 
            if(d >= y && invalidIsland == false)
                radarArea.push(make_pair(x-pow(d*d-y*y,0.5), x+pow(d*d-y*y,0.5)));
        }
        if(invalidIsland){
            radarCount = -1;
        }else{
            unionRadar(radarArea, radarCount);
        }
        cout << "Case " << t << ": " << radarCount << endl;
    }
    return 0;
}
*/