/// Kazuki Hoshino


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
#define inf 1000000000
#define mod 1000000007
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for(int i =a; i >=b; i--)
#define dmp(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl
#define fs first
#define sc second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define mt make_tuple
//#define endl '\n'
typedef tree<
int,
null_type,less<int>,
rb_tree_tag,tree_order_statistics_node_update>
ordered_set;
int n,k,vis[2005],dist[2005],ans=1e9,cnt,smax;
vi adj[2005];
set<int> st;
void dfs(int s, int p){
	if(dist[s]>(k+1)/2)return ;
	if(k%2 && dist[s]==(k+1)/2){
		st.insert(s);
	}
	else
	cnt++;
	for(auto t:adj[s]){
		if(t!=p){
			dist[t]=dist[s]+1;
			dfs(t,s);
		}
	}
}
signed main(){
ios::sync_with_stdio(0);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
cin >> n >> k;
for(int i=1;i<n;i++){
	int x,y;
	cin >> x >> y;
	adj[x].pb(y);
	adj[y].pb(x);
}
for(int i=1;i<=n;i++){
	cnt = 1;
	smax = 0;		
	for(int j=1;j<=n;j++){
		dist[i]=1e18;
	}
	for(auto t:adj[i]){

		dist[t]=1;
		dfs(t,i);
		smax = max(smax, (int)st.size());
		st.clear();

	}
	ans = min(ans, n-cnt-smax );
}
cout << ans << endl;
return 0;}
///....
