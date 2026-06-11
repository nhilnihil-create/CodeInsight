#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1e9+7;
const LL LINF=1LL<<62;
const int INF=1<<30;

vector<int> v[100001],dp(100001,-1);

int dfs(int k){
    if(~dp[k]) return dp[k];
    int ret = 0;
    vector<int> t;
    for (int i = 0; i < v[k].size(); i++) {
        t.pb(dfs(v[k][i]));
    }
    sort(ALL(t));
    for (int i = 0; i < t.size(); i++) {
        ret = max((int)t.size()-i+t[i],ret);
    }
    return dp[k] = ret;
}



int main(){
    int n;cin >> n;
    for (int i = 2; i <= n; i++) {
        int a;cin >> a;
        v[a].pb(i);
    }
    cout << dfs(1) << endl;
    return 0;
}
