#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;


vector<int> G[1<<17];
int n,k;
int ans;


int dfs(int v,int c){
    int ret = 0;
    for (int i = 0; i < G[v].size(); i++) {
        int res = dfs(G[v][i],c+1);
        if(res == k && v != 0) ans++;
        else ret = max(ret,res);
    }
    return ret+1;
}


int main(){
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a;cin >> a;
        a--;
        if(i==0) ans+=(a!=i);
        else G[a].pb(i);
    }
    dfs(0,0);
    cout << ans << endl;
    return 0;
}

