// Jump, and you will find out how to unfold your wings as you fall.

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

ll a[maxn],W[maxn],cnt[maxn];
vector<int>v[maxn];

void dfs1(int u,int par=-1){
    if(sz(v[u])==1) {W[u]=a[u]; return;}
    W[u]=2*a[u];
    for(int y:v[u]){
	if(y!=par){
	    dfs1(y,u);
	    W[u]-=W[y];
	}
    }
}
ll dfs2(int u,int par=-1){
    if(sz(v[u])==1) return -W[u];
    ll sm=0;
    for(int y:v[u]){
	if(y!=par){
	    sm+=dfs2(y,u);
	}
    }
    ll num=W[u]+sm;
    if(num>0 || num&1) cout<<"NO"<<endl,exit(0);
    cnt[u]=(-num)/2;
    return -W[u];
}
ll dfs3(int u,int par=-1){
    if(sz(v[u])==1) return W[u];
    ll check=cnt[u]*2,sum=0;
    for(int y:v[u]){
	if(y!=par){
	    ll num=dfs3(y,u);
	    sum+=num;
	    check-=min(num,cnt[u]);
	}
    }
    if(check>0) cout<<"NO"<<endl,exit(0);
    return sum-cnt[u]*2;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
	cin>>a[i];
    }
    for(int i=1;i<=n-1;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    if(n==2){
	return cout<<(a[1]==a[2]?"YES":"NO")<<endl,0;
    }
    int r=1;
    for(int i=1;i<=n;i++){
	if(sz(v[i])>1) r=i;
    }
    dfs1(r);
    if(W[r]!=0) return cout<<"NO"<<endl,0;
    dfs2(r);
    if(dfs3(r)!=0) return cout<<"NO"<<endl,0;
    return cout<<"YES"<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.
