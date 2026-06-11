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
vi adj[(int)2e5];
map<int, bool> vis;
map<int, bool> col;
bool bi = true;
void dfs(int cur, bool c){
    if(vis[cur]){
        if(col[cur] != c)bi = false;
        return; 
    }
    vis[cur] = true;
    col[cur] =c;
    for(int child:adj[cur]){
        dfs(child, !c);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n, m;cin >> n >> m;
    FOR(i, m){
        int x, y;cin >> x >> y;
        x--, y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int comp1 = 0, bii= 0, bi1 = 0;
    int prev = 0;
    FOR(i, n){
        if(!vis[i]){
            bi = true;
            dfs(i, false);
            int gp = vis.size() - prev;
            if(gp == 1)comp1++;
            else if(bi)bii++;
            else bi1++;
        } 
        prev = vis.size(); 
    }

   // debug(bii);
    
    //debug(bi1);
    int ans = comp1*comp1 + comp1 * (n- comp1) *2;
    //debug(ans);
    ans += bi1*bii*2;
    ans += bii*bii*2;
    ans += bi1*bi1;
    cout << ans;
}



