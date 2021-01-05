/*
 * @Author: your name
 * @Date: 2020-09-21 20:35:02
 * @LastEditTime: 2021-01-04 23:25:45
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /第一次作业/汉诺塔问题(Hanoi)/main.cpp
 */

#include <iostream>
using namespace std;

void hanoi(int n, char a, char b, char c){
    if(n == 1){
        cout << n << ":" << a << "->" << c << endl;
        return;
    }
    hanoi(n-1, a, c, b);
    cout << n << ":" << a << "->" << c << endl;
    hanoi(n-1, b, a, c);
    return;
}

int main(){
    int n;
    char a, b, c;
    cin >> n >> a >> b >> c;
    hanoi(n, a, b, c);
    return 0;
}

/*
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace  std;

int n;
char Ca, Cb, Cc;

void hanoi(int n, char a, char b, char c){
    if(n ==  1){
        printf("%d:%c->%c\n", n, a, c);
        return;
    }
    hanoi(n - 1, a, c, b);
    printf("%d:%c->%c\n", n, a, c); 
    hanoi(n - 1, b, a, c);
    return;
}

int main(){
    cin >> n >> Ca >> Cb >> Cc;
    hanoi(n, Ca, Cb, Cc);
    return 0;
}
*/
