#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 998244353

using namespace std;
using ll = long long;
using ldb = long double;

int main() {
    ll x, y; cin >> x >> y;
    ll ans = 0;
    if (x >= 0) {
        if (y >= x) ans = abs(abs(x) - abs(y));
        else if (0 < y && y < x) ans = abs(abs(x) - abs(y)) + 2;
        else if (y <= 0) ans = abs(abs(x) - abs(y)) + 1;
    }
    else {
        if (x<=y&&y<=0) ans = abs(abs(x) - abs(y));
        else if (y < x) ans = abs(abs(x) - abs(y)) + 2;
        else if (0 < y) ans = abs(abs(x) - abs(y)) + 1;
    }
    cout << abs(ans) << endl;

}

