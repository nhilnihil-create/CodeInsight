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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iterator>

#define ios ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
#define S second
#define F first
#define pb push_back
#define nl '\n'
#define NL cout << '\n';
#define EX exit(0)
#define all(s) s.begin(), s.end()
#define FOR(i, start, finish, k) for(int i = start; i <= finish; i += k)

const int MXN = 2e5 + 1;
const long long MNN = 5e3 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const int OO = 1e9 + 500;

typedef long long llong;
typedef unsigned long long ullong;

using namespace std;

int n, clr[MXN], cnt[3];
vector<int> q[MXN];

void dfs(int x, int p){
    queue<int> que;
    que.push(1);
    que.push(n);
    for(int i = 1; i <= n; i++) clr[i] = -1;
    clr[1] = 0;
    clr[n] = 1;
    while(que.size() != 0){
        int x = que.front();
        cnt[clr[x]]++;
        que.pop();
        for(int i = 0; i < q[x].size(); i++){
            int to = q[x][i];
            if(clr[to] == -1){
                clr[to] = clr[x];
                que.push(to);
            }
        }
    }
}

int main () {
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        q[u].pb(v);
        q[v].pb(u);
    }
    dfs(1, 0);
    if(cnt[0] > cnt[1]){
        cout << "Fennec";
    }else{
        cout << "Snuke";
    }
    return 0;
}
