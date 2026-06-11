//优化
#pragma GCC optimize(2)
//C
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//C++
#include<algorithm>
#include<iostream>
#include<istream>
#include<iomanip>
#include<cstdio>
#include<stack>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<set>
//宏定义
#define it set<ll>::iterator
#define N 1010
//定义+命名空间
typedef long long ll;
typedef unsigned long long ull;
const int mod = 998244353;
const int INF = 1e9;
const int maxn = 1e6 + 5;
using namespace std;
//全局变量//
//函数区//
ll max(ll a, ll b) { return a > b ? a : b; }
ll min(ll a, ll b) { return a < b ? a : b; }
bool judge(ll x, ll y) {
    if (x >= 0 && y >= 0) return 1;
    if (x <= 0 && y <= 0) return 1;
    return 0;
}
//主函数//
int main() {
 
    ll x, y;
    cin >> x >> y;
 
    if (y > x) {
        if (judge(x, y))
            cout << y - x << endl;
        else {
            ll temp = abs(x + y);
            cout << temp + 1 << endl;
        }
    }
    else if (x >= 0 && y >= 0) {
        if (y != 0)
            cout << x - y + 2 << endl;
        else cout << x - y + 1 << endl;
    }
    else if (x <= 0 && y <= 0) {
        if (x != 0)
            cout << x - y + 2 << endl;
        else cout << x - y + 1 << endl;
    }
    else if (x >= 0 && y <= 0) {
        ll temp = abs(x + y);
        cout << temp + 1 << endl;
    }
    return 0;
}
//分割线---------------------------------QWQ
/*
 
1 2 5
4 3 1
 
1 2 4
5 2 1
*/
 
/*
 
f(n) = ln(n) + C + 1 / 2 * n
double C = 0.57721566490153286060651209;
 
*/