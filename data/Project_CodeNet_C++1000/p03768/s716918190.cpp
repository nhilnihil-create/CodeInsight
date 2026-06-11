#include<bits/stdc++.h>
#define pb           push_back
#define pii          pair<int,int>
#define vi           vector<int>
#define vpii         vector<pair<int,int>>
#define gph          map<int, vector<int>>
#define mp           make_pair
#define FOR(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD0(i, n) for (int i = (int)n; i >= 0; i--)
#define FORD1(i, n) for (int i = (int)n; i >= 1; i--)
#define FORS(i, n) for(; i < (int)(n); i++)
#define debug(X) { cout << #X << " = " << (X) << endl; }
#define printArr(A,n) { cout << #A << " = "; FOR(i,n) cout << A[i] << ' '; cout << endl; }
using namespace std;
#define int long long int
const int lim = (int)2e5 + 5;
vi adj[lim];
int dp[lim][11] = {0};
void dfs(int cur, int dep, int color){
    if(dep < 0)return;
    if(dp[cur][dep])return;
    int i = dep;
    while(i >= 0 && !dp[cur][i]){
        dp[cur][i] = color;
        i--;
    }
    for(int child: adj[cur]){
        dfs(child, dep - 1, color);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int n, m;cin >> n >> m;
    int x, y, a, b, c;
    FOR(i, m){
        cin >>x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int q;cin >> q;
    vector<pair<int, pii>> info;
    FOR(i, q){
        cin >> a >> b >> c;
        info.pb(mp(a, mp(b, c)));
    }
    FOR(i, q){
        dfs(info.back().first, info.back().second.first, info.back().second.second);
        info.pop_back();
    }
    FOR(i, n){
        cout << dp[i+1][0] << endl;
    }
}


