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
#include <unordered_map>

#define ios ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
#define S second
#define F first
#define pb push_back
#define nl '\n'
#define all(s) s.begin(), s.end()
#define fo(i, start, finish) for(int i = start; i <= finish; i ++)
#define y1 kdfjsalsdkf

const long long MXN = 1e5 + 10;
const long long MNN = 5e3 + 1;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long long OO = 1e9 + 500;

typedef long long llong;
typedef unsigned long long ullong;

using namespace std;

int n, k, cnt[MNN][MNN], ans = OO, u[MNN], v[MNN];
vector<int> g[MNN];

void dfs(int x, int p, int batya, int lvl){
    for(int i : g[x]){
        if (i == p) continue;
        dfs(i, x, batya, lvl + 1);
    }
    if(lvl > k / 2){
        cnt[batya][0]++;
    }
}

int main(){
    ios;
    cin >> n >> k;
    for(int i = 1; i < n; i++){
        cin >> u[i] >> v[i];
        g[u[i]].pb(v[i]);
        g[v[i]].pb(u[i]);
    }
    if(k % 2 == 0){
        for(int i = 1; i <= n; i++){
            dfs(i, 0, i, 0);
            ans = min(ans, cnt[i][0]);
        }
    } else {
        for(int i = 1; i < n; i++){
            cnt[u[i]][0] = 0;
            cnt[v[i]][0] = 0;
            dfs(u[i], v[i], u[i], 0);
            dfs(v[i], u[i], v[i], 0);
            ans = min(ans, cnt[u[i]][0] + cnt[v[i]][0]);
        }
    }
    cout << ans;
    return 0;
}


//
//
//
