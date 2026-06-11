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
vi adj[(int)1e5 + 5];
int dfs(int cur, int P){
    int xr = 0;
    int cnt =0;
    for(int child: adj[cur]){
        if(child == P)continue;
        xr ^= (dfs(child, cur) + 1);
        cnt++;
    }
    return xr;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int n;cin >> n;
    int x, y;
    FOR(i, n -1){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int ans = dfs(1, -1);
    if(ans)cout << "Alice";
    else cout << "Bob";

}


