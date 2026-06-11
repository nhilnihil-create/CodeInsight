#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) cout << #x << " = " << (x) << endl;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
vector<int>g[123456];
int dp[123456][11];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,q;
    cin >> n >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin >> q;
    vector<int>c;
    memset(dp,-1,sizeof(dp));
    rep(i,q){
        int v,d,cc;
        cin >> v >> d >> cc;
        v--;
        dp[v][d] = i;
        c.push_back(cc);
    }
    for(int i = 10; i > 0; i--){
        rep(j,n){
            for(int x:g[j]){
                dp[x][i-1] = max(dp[x][i-1], dp[j][i]);
            }
        }
    }
    rep(i,n){
        int k = *max_element(dp[i],dp[i]+11);
        if(k==-1)cout << 0 << "\n";
        else cout << c[k] << "\n";
    }
}