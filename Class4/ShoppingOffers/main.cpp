/*
 * @Author: your name
 * @Date: 2020-11-24 15:59:52
 * @LastEditTime: 2020-11-28 16:29:01
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /projects/AlgorithmDesign/Class4/ShoppingOffers/main.cpp
 */

// 1、使用六进制的方式来表示这物种物品，每一种物品最多有0，1，2，3，4，5这六种状态，每一种物品对应一位六进制数，这样物品的状态就可通过一个六进制数来表示，最多有5种物品，这个表示状态的六进制数最多有五位，分别对应的十进制数为，1，6，36，216，1296，物品的状态为1*i1+6*i2+36*i3+216*i4+1296*i5;
// 2、题目要求得到最低的购买价格，我们可以逆向转换为找到一个方案可以获得最多的优惠。每一种offer与不使用优惠购买相同物品都有一个优惠的价格，这样就转变成了一个无穷背包问题，每个offer在满足物品”空间（个数上限）“的条件下，可以无限次的应用

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

bool enoughItem(int x, int y) {
    for (int i = 0; i < 6; i++) {
        if (x % 6 < y % 6) return false;
        x /= 6;
        y /= 6;
    }
    return true;
}

int b, s;

int main(){
    while(cin >> b){
        int basket = 0;
        int totalPrice = 0;
        vector<int> code;
        vector<int> price;
        vector<int> base = {1,6,36,216,1296};
        vector<vector<int>> offers;
        int dp[1290*10] = {0};
        for(int i = 0; i < b; ++i){
            int c, k, p;
            cin >> c >> k >> p;
            code.push_back(c);
            basket+=k*base[i];
            price.push_back(p);   
            totalPrice += k*p;
        }
        cin >> s;
        for(int i = 0; i < s; ++i){
            int n;
            cin >> n;
            int originalPrice = 0;
            int benifit = 0;
            int package = 0;
            for(int j = 0; j < n; ++j){
                int c, k;
                cin >> c >> k;
                package += base[find(code.begin(),code.end(),c)-code.begin()]*k;
                originalPrice += price[find(code.begin(),code.end(),c)-code.begin()]*k;
            }
            int p;
            cin >> p;
            benifit = originalPrice - p;
            vector<int> offer = {package, benifit};
            offers.push_back(offer);
        }
        for(int i = 1; i <= s; ++i){
            for(int j = offers[i-1][0]; j <= basket; ++j){
                if(enoughItem(j, offers[i-1][0])){
                    dp[j] = max(dp[j], dp[j-offers[i-1][0]]+offers[i-1][1]);
                }
            }
        }
        int maxBenifit = dp[basket];
        cout << totalPrice - maxBenifit << endl;
    }
    return 0;
}