#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using ll = long long;
using namespace std;
int main () {
    string s;
    cin >> s;
    // cout << s ;
    int len;
    len = s.size() -2;
    char a = s.front();
    char b = s.back();
    cout << a ;
    cout << len ;
    cout << b ;

    return 0;
}