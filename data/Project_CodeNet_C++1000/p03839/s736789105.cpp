//
//  ROIGold.cpp
//  Main calisma
//
//  Created by Rakhman on 05/02/2019.
//  Copyright © 2019 Rakhman. All rights reserved.
//

#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iterator>
#include<unordered_map>

#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define S second
#define F first
#define pb push_back
#define nl '\n'
#define NL cout << '\n';
#define EX exit(0)
#define all(s) s.begin(), s.end()
#define FOR(i, start, finish, k) for(llong i = start; i <= finish; i += k)

const long long MXN = 3 * 1e6 + 1;
const long long MNN = 4444;
const long long MOD = 10;
const long long INF = 1e9;
const long long OO = 1e9 + 1;
const double pi = acos(-1.0);

typedef long long llong;
typedef unsigned long long ullong;

using namespace std;

llong n, k, b[MXN], p[MXN], sum, mx, pl[MXN];

llong calc(int ind){
    llong x = pl[n] - pl[ind] + pl[ind - k];
    return max(x, x + p[ind] - p[ind - k]);
}

int main(){
    ios;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        p[i] = p[i - 1] + b[i];
        pl[i] = pl[i - 1] + max(0LL, b[i]);
    }
    for(int i = k; i <= n; i++){
        mx = max(calc(i), mx);
    }
    cout << mx;
    return 0;
}
