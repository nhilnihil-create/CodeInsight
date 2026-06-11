#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
int dp[100010];
vector<int> G[100010];
int dfs(int u = 0) {
    int ret = 0;
    vector<int> v;
    for(auto &e: G[u]) {
        v.push_back(dfs(e));
    }
    if(v.size() == 0) return 0;
    sort(v.begin(), v.end(), greater<int>());
    rep(i, v.size()) {
        ret = max(ret, v[i] + i + 1);
    }
    return ret;
} 

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    rep(i, N - 1) {
        int e; cin >> e;
        e--;
        G[e].push_back(i + 1);
    }
    cout << dfs() << endl;

    return 0;
}
