#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
ll a[100005];
vector<int>edge[100005];
bool flag = true;
ll dfs(int v,int u,int d){
	if(edge[v].size() == 1) return a[v];
	ll cnt = 0,mx = 0;
	rep(i,edge[v].size()){
		if(edge[v][i]==u) continue;
		ll A = dfs(edge[v][i],v,d+1);
		cnt += A;
		mx = max(mx,A);
	}
	ll pr = 0;
	if(mx*2 > cnt){
		pr = cnt-mx;
	}
	else{
		pr = cnt/2;
	}
	if(d == 0){
	    if(pr*2 != cnt || a[v] != pr) flag = false;
	}
	else{
	    if(cnt-pr<=a[v] && a[v]<=cnt);
	    else flag = false;
	}
	return cnt-(cnt-a[v])*2LL;
}
int main(){
	cin>>n;
	repn(i,n)cin>>a[i];
	rep(i,n-1){
		int a,b; cin>>a>>b;
		edge[a].pb(b);
		edge[b].pb(a);
	}
	if(n == 2){
	    puts(a[1]!=a[2]?"NO":"YES");
	    return 0;
	}
	int v = -1;
	repn(i,n){
		if(edge[i].size()>=2){
			v = i;
			break;
		}
	}
	dfs(v,-1,0);
	puts(!flag?"NO":"YES");
}