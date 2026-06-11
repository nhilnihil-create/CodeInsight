#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define dbg(...) do{cerr<<__LINE__<<": ";dbgprint(#__VA_ARGS__, __VA_ARGS__);}while(0);

using namespace std;

namespace std{template<class S,class T>struct hash<pair<S,T>>{size_t operator()(const pair<S,T>&p)const{return ((size_t)1e9+7)*hash<S>()(p.first)+hash<T>()(p.second);}};template<class T>struct hash<vector<T>>{size_t operator()(const vector<T> &v)const{size_t h=0;for(auto i : v)h=h*((size_t)1e9+7)+hash<T>()(i)+1;return h;}};}
template<class T>ostream& operator<<(ostream &os, const vector<T> &v){os<<"[ ";rep(i,v.size())os<<v[i]<<(i==v.size()-1?" ]":", ");return os;}template<class T>ostream& operator<<(ostream &os,const set<T> &v){os<<"{ "; for(const auto &i:v)os<<i<<", ";return os<<"}";}
template<class T,class U>ostream& operator<<(ostream &os,const map<T,U> &v){os<<"{";for(const auto &i:v)os<<" "<<i.first<<": "<<i.second<<",";return os<<"}";}template<class T,class U>ostream& operator<<(ostream &os,const pair<T,U> &p){return os<<"("<<p.first<<", "<<p.second<<")";}
void dbgprint(const string &fmt){cerr<<endl;}template<class H,class... T>void dbgprint(const string &fmt,const H &h,const T&... r){cerr<<fmt.substr(0,fmt.find(","))<<"= "<<h<<" ";dbgprint(fmt.substr(fmt.find(",")+1),r...);}
typedef long long ll;typedef vector<int> vi;typedef pair<int,int> pi;const int inf = (int)1e9;const double INF = 1e12, EPS = 1e-9;

const int mod = 1e9 + 7;
const int MX = 1000100;
ll dp[MX], s[MX];

int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	int n; cin >> n;
	dp[0] = 1;
	ll ans = 0;
	
	rep(i, n){
		(s[i + 1] += s[i]) %= mod;
		(dp[i] += s[i]) %= mod;
		(dp[i + 1] += dp[i]) %= mod;
		
		//for(int j = i + 3; j <= n; j++) (dp[j] += dp[i]) %= mod;
		(s[i + 3] += dp[i]) %= mod;
		
		if(i < n - 1){
			//for(int j = max(2, n - i); j <= n; j++) (ans += dp[i]) %= mod;
			(ans += dp[i] * max(0, n - max(2, n - i) + 1)) %= mod;
			
			
			(ans += (n - 1ll) * (n - 1) % mod * dp[i] % mod) %= mod;
		}
		else{
			(ans += (n - 1) * dp[i]) %= mod;
		}
	}
	(ans += dp[n] + s[n]) %= mod;
	cout << ans << endl;
	
	return 0;
}