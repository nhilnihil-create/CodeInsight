#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define pi pair<int,int>
#define vp vector<pair<int,int>>
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define MEMSET(a) memset(a,0,sizeof(a))
#define inf (1ll<<60)
#define Yes(f) cout<<(f?"Yes":"No")<<endl
#define yes(f) cout<<(f?"yes":"no")<<endl
#define YES(f) cout<<(f?"YES":"NO")<<endl
#define SORT(v) sort(all(v))
#define RSORT(v) sort(all(v), greater<int>())
#define VI(a,n) vi a(n); rep(i,n)cin>>a[i];
#define sq(n) (n)*(n)

using namespace std;

const int mod=1e9+7;

void run();

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
}

signed main(){
    init();
    run();
    return 0;
}

const int limit=100010;
using edge=struct{int to;int cost;};
vector<edge> tree[limit];

// use "dfs(beginning_vertex_number, -1, 0)"
void dfs(int v,int p,int d,vi &depth){
	depth[v]=d;
	for(auto &e:tree[v]){
		if(e.to==p)continue;
		dfs(e.to,v,d+e.cost,depth);
	}
}

void run(){
    int n;
    cin>>n;
    rep(i,n-1){
        int a,b,c;
        cin>>a>>b;
        a--,b--;
        tree[a].pb({b,1});
        tree[b].pb({a,1});
    }
    vi depth1(limit),depth2(limit);
    dfs(0,-1,0,depth1);
    dfs(n-1,-1,0,depth2);
    int f=0,s=0;
    rep(i,n){
        if(depth1[i]<=depth2[i])f++;
        else s++;
    }
    // cout<<f<<" "<<s<<endl;
    cout<<(f>s?"Fennec":"Snuke")<<endl;
}