/*
 * @Author: your name
 * @Date: 2020-11-07 19:35:11
 * @LastEditTime: 2021-01-13 17:36:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /projects/AlgorithmDesign/Class4/Raid/main.cpp
 */


/*
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <limits>
using namespace std;

class point{
public:
    double x, y;
    int stationOrAgent;
    point(double _x, double _y, int _stationOrAgent): x(_x), y(_y), stationOrAgent(_stationOrAgent){}
};

bool cmpx(const point* a, const point* b){
    return a->x < b->x;
}

bool cmpy(const point* a, const point* b){
    return a->y < b->y;
}

double findMinDistance(vector<point*>& stationsAndAgents, long long start, long long end){
    // 如果区间中只有一个点，直接返回一个极大值
    if(end <= start){
        return __DBL_MAX__;
    }
    
    // 从中间划分，分别计算左右两侧的最近距离
    long long mid = (start+end)/2;
    double minDistanceLefthalf = findMinDistance(stationsAndAgents, start, mid);
    double minDsitanceRighthalf = findMinDistance(stationsAndAgents, mid+1, end);
    double minDistance = min(minDistanceLefthalf, minDsitanceRighthalf);
    
    // 将按照x坐标排序的序列，围绕在上次划分的中点处，左右两侧距离为两侧最小距离的点记录下来，然后按照y坐标排序
    vector<point*> temp;
    for(long long i = start; i <= end; ++i){
        if(abs(stationsAndAgents[i]->x - stationsAndAgents[mid]->x) <= minDistance){
            temp.push_back(stationsAndAgents[i]);
        }
    }
    sort(temp.begin(), temp.end(), cmpy);

    // 对这个区间中的每个点，检查紧随其后的11个点与其的距离，是否存在比左右两侧最小距离更小的距离
    for(long long i = 0; i < temp.size(); ++i){
        for(long long j = i+1; j < temp.size() && j - i < 12; ++j){
            if(temp[j]->stationOrAgent != temp[i]->stationOrAgent){
                double distance = pow(pow(temp[i]->x - temp[j]->x,2) + pow(temp[i]->y - temp[j]->y,2),0.5);
                if(distance < minDistance) minDistance = distance;
            }
        }
    }

    return minDistance;
}

int main(){
    cout << fixed << setprecision(3);
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<point*> stationsAndAgents;
        for(long long i = 0; i < n; ++i){
            double x, y;
            cin >> x >> y;
            point* temp = new point(x, y, 0);
            stationsAndAgents.push_back(temp);
        }
        for(long long i = 0; i < n; ++i){
            double x, y;
            cin >> x >> y;
            point* temp = new point(x, y, 1);
            stationsAndAgents.push_back(temp);
        }
        sort(stationsAndAgents.begin(), stationsAndAgents.end(), cmpx);
        cout << findMinDistance(stationsAndAgents, 0, n*2-1) << endl;
    }
    return 0;
}
*/