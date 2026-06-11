#include <algorithm>
#include <bitset>
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
int nx[200005][26];
int dp[200005];
int dp2[200005];
int dfs(int x){
    if(dp[x]!=-1)return dp[x];
    vector<int>a;
    rep(i,26)a.push_back(dfs(nx[x][i])+1);
    int id = (int)(min_element(a.begin(),a.end())-a.begin());
    dp2[x] = id;
    return dp[x] = a[id];
}
int main(){
    string s;
    cin >> s;
    int a[26];
    s = "?" + s;
    int n = (int)s.size();
    rep(i,26)a[i] = n;
    rep(i,26)nx[n-1][i] = nx[n][i] = n;
    rep(i,n)dp[i] = -1;
    dp[n] = 0;
    for(int i = n-1; i >= 0; i--){
        rep(j,26)nx[i][j] = a[j];
        a[s[i]-'a'] = i;
    }
    dfs(0);
    string ans;
    int pos = 0;
    rep(i,dp[0]){
        ans += 'a'+dp2[pos];
        pos = nx[pos][dp2[pos]];
    }
    cout << ans << endl;
    
}