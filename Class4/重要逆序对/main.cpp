/*
 * @Author: your name
 * @Date: 2020-10-27 13:15:32
 * @LastEditTime: 2021-01-13 11:40:27
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /projects/AlgorithmDesign/Class4/重要逆序对/main.cpp
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void mergesort(vector<int>& nums, int start, int end, long long& importantCount){
    if(start == end){
        return;
    }
    int mid = (start + end)/2;
    mergesort(nums, start, mid, importantCount);
    mergesort(nums, mid+1, end, importantCount);
    vector<int> tmp;
    for(int i = start, j = mid+1; i <= mid && j <= end;){
        if(nums[i]>2*nums[j]){
            importantCount+=mid-i+1;
            j++;
        }else{
            i++;
        }
    }
    int i = start, j = mid+1;
    while(i <= mid && j <= end){
        if(nums[i]<nums[j]){
            tmp.push_back(nums[i]);
            i++;
        }else{
            tmp.push_back(nums[j]);
            j++;
        }
    }
    while(i<=mid){
        tmp.push_back(nums[i]);
        i++;
    }
    while(j<=end){
        tmp.push_back(nums[j]);
        j++;
    }
    for(int i = start; i <= end; ++i){
        nums[i] = tmp[i-start];
    }
    return;
}

int main(){
    int n;
    cin >> n;
    while(n != 0){
        vector<int> nums(n, 0);
        for(int i = 0; i < n; ++i){
            cin >> nums[i];
        }
        long long importantReversePairCount = 0;
        mergesort(nums, 0, n-1, importantReversePairCount);
        cout << importantReversePairCount << endl;
        cin >> n;
    }
    return 0;
}

/*
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

long long importantReverse(int start, int end, vector<int>& nums){
    if(end - start == 1) return 0;
    long long res = 0;
    int mid = (start+end)/2;
    res += importantReverse(start, mid, nums);
    res += importantReverse(mid, end, nums);
    vector<int> temp;
    int i,j;
    for(i = start, j = mid; i < mid && j < end;){
        if(nums[i]>2*nums[j]){
            j++;
        }else{
            res+=j-mid;
            i++;
        }
    }
    while (i != mid){
        res+=j-mid;
        i++;
    }

    for(i = start, j = mid; i < mid && j < end;){
        if(nums[i]>nums[j]){
            temp.push_back(nums[j]);
            j++;
        }else{
            temp.push_back(nums[i]);
            i++;
        }
    }
    while(i!=mid){
        temp.push_back(nums[i]);
        i++;
    }
    while(j!=end){
        temp.push_back(nums[j]);
        j++;
    }
    for(int i = start; i < end; ++i) nums[i] = temp[i-start];
    return res;
}

int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        vector<int> nums;
        int t = n;
        while(t--){
            int num;
            cin >> num;
            nums.push_back(num);
        }
        cout << importantReverse(0, n, nums) << endl;
    }
    return 0;
}
*/