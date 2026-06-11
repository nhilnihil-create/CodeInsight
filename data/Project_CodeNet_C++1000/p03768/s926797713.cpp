#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,int> Pi;
#define rep(i,n) for(ll i=0;i<n;i++)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define fi first
#define se second
#define endl "\n"

template<typename T> inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<typename T> ostream& operator<<(ostream& s,const complex<T>& d) {return s<<"("<<d.real()<<", "<<d.imag()<< ")";}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const pair<T1,T2>& d) {return s<<"("<<d.first<<", "<<d.second<<")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& d){int len=d.size();rep(i,len){s<<d[i];if(i<len-1) s<<" ";}return s;}
template<typename T> ostream& operator<<(ostream& s,const vector<vector<T>>& d){int len=d.size();rep(i,len){s<<d[i]<<endl;}return s;}
template<typename T> ostream& operator<<(ostream& s,const set<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const map<T1,T2>& m){s<<"{"<<endl;for(auto itr=m.begin();itr!=m.end();++itr){s<<" "<<(*itr).first<<" : "<<(*itr).second<<endl;}s<<"}"<<endl;return s;}

const ll mod=1e9+7;
const ll inf=1e17;
const int INF=1e9;
const double PI=acos(-1);
const double EPS=1e-10;

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<vector<int>> g(n);
	rep(i,m){
		int a,b;
		cin>>a>>b;
		a--,b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int q;
	cin>>q;
	vector<int> v(q),d(q),c(q);
	rep(i,q) cin>>v[i]>>d[i]>>c[i];
	vector<int> ans(n,0);
	vector<vector<bool>> dp(n,vector<bool>(11,false));
	auto dfs=[&](auto &dfs,int v,int d,int c)->void{
		if(dp[v][d]) return ;
		if(ans[v]==0) ans[v]=c;
		dp[v][d]=true;
		if(d==0) return ;
		dfs(dfs,v,d-1,c);
		for(auto to:g[v]){
			dfs(dfs,to,d-1,c);
		}
	};
	for(int i=q-1;i>=0;i--){
		v[i]--;
		dfs(dfs,v[i],d[i],c[i]);
	}
	cout<<ans<<endl;
}