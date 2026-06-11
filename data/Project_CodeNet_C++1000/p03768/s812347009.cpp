#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
//const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
bool dp[12][100005];
int ans[100005];
V<int> g[100005];
void solve(int d,int cur,int c){
	 if(dp[d][cur])return;
	 dp[d][cur]=1;
	 if(ans[cur]==0)ans[cur]=c;
	 if(d==0)return;
	 if(!dp[d-1][cur]){
		solve(d-1,cur,c);
	 }
	 for(int v:g[cur]){
		 solve(d-1,v,c);
	 }
}
struct Data{
	int v,d,c;
};
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[--a].push_back(--b);
		g[b].push_back(a);
	}
	int q;
	cin>>q;
	V<Data> d(q);
	for(int i=0;i<q;i++){
		cin>>d[i].v>>d[i].d>>d[i].c;
	}
	reverse(all(d));
	for(int i=0;i<q;i++){
		solve(d[i].d,d[i].v-1,d[i].c);
	}
	for(int i=0;i<n;i++)cout<<ans[i]<<"\n";
}