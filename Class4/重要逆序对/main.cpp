/*
 * @Author: your name
 * @Date: 2020-10-27 13:15:32
 * @LastEditTime: 2020-11-06 19:27:58
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /projects/AlgorithmDesign/Class4/重要逆序对/main.cpp
 */
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