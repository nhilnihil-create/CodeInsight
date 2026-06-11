#include<bits/stdc++.h>
#define pb           push_back
#define pii          pair<int,int>
#define vi           vector<int>
#define vii         vector<pair<int,int>>
#define mp           make_pair
#define FOR(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD0(i, n) for (int i = (int)n; i >= 0; i--)
#define FORD1(i, n) for (int i = (int)n; i >= 1; i--)
#define debug(X) { cout << #X << " = " << (X) << endl; }
#define endl '\n'
#define int long long int
using namespace std;
vi adjList[(int)1e5 + 1];
int k;
pii dfs(int cur){
    int ans = 0;
    int dp = 0;
    for(int child: adjList[cur]){
        pii temp = dfs(child);
        ans += temp.first;
        if(temp.second == k - 1){
            ans++;
            temp.second = -1;
        }
        dp = max(dp, 1 + temp.second);
    } 
    return mp(ans, dp);
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n;cin >> n;
    cin >> k;
    vi dest(n);
    FOR(i, n){cin >> dest[i]; if(i != 0)adjList[dest[i]].pb(i + 1);}
    int ans = 0;
    ans += (dest[0] != 1);

    for(int child:adjList[1]){
        ans += dfs(child).first;
    }

    cout << ans;
}


