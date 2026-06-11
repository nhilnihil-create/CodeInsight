//
//  Road2Master.cpp
//  Road2Master
//
//  Created by Rakhman Abdirashov on 12/14/19.
//  Copyright © 2019 Rakhman Abdirashov. All rights reserved.
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
#define no_answer {cout << "NO"; exit(0);}
#define vectors vector<vector<llong> >
#define FOR(i, start, finish, k) for(llong i = start; i <= finish; i += k)
 
const long long MXN = 2e5 + 10;
const long long MNN = 1e4 + 520;
const long long MOD = 10007;
const long long INF = 1e18;
const long long OO = 1e9;
 
typedef long long llong;
typedef unsigned long long ullong;
 
using namespace std;

int n, m;
vector<int> g[MXN];
bool used[MXN];
deque<int> ans;

void dfs(int x){
    used[x] = 1;
    ans.push_back(x);
    for(int i = 0; i < g[x].size(); i++){
        int to = g[x][i];
        if(used[to] == 0){
            dfs(to);
            break;
        }
    }
}

void dfs1(int x){
    used[x] = 1;
    if(x != 1) ans.push_front(x);
    for(int i = 0; i < g[x].size(); i++){
        int to = g[x][i];
        if(used[to] == 0){
            dfs1(to);
            break;
        }
    }
}

int main(){
    ios;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    dfs1(1);
    cout << ans.size() << nl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }
}
