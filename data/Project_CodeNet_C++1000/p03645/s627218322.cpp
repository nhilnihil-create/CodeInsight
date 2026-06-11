#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define Endl '\n'
#define cont continue
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/__gcd(a,b)
#define pb push_back
#define mp make_pair
#define mem(x) memset(x, 0, sizeof(x))

const ll inf=1e18;
const int mod=1e9+7;
inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
const int mxn = 2e5+10;
vector<int>adj[mxn];

	
	
int main(){
    fast;

    int tt = 1;
    //cin>>tt;
    for(int tc = 1; tc <= tt; tc++) {
        int n,m;
        cin>>n>>m;
        for(int i = 0; i < m; i++) {
			int x,y;
			cin>>x>>y;
			//adj[x].pb(y);
			adj[y].pb(x);
		}
		for(int x : adj[n]) {
			sort(adj[x].begin(),adj[x].end());
			if(binary_search(adj[x].begin(),adj[x].end(),1)) return cout<<"POSSIBLE\n",0;
		}
        cout<<"IMPOSSIBLE\n";
        
    }



return 0;
}
