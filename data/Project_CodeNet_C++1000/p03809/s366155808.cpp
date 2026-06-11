#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <list>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const ll INF = 1LL<<29;
const ll mod = 1e9+7;
#define rep(i,n) for(int (i)=0;(i)<(ll)(n);++(i))
#define repd(i,n,d) for(ll (i)=0;(i)<(ll)(n);(i)+=(d))
#define all(v) (v).begin(), (v).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset((m),(v),sizeof(m))
#define chmin(X,Y) ((X)>(Y)?X=(Y),true:false)
#define chmax(X,Y) ((X)<(Y)?X=(Y),true:false)
#define fst first
#define snd second
#define UNIQUE(x) (x).erase(unique(all(x)),(x).end())
template<class T> ostream &operator<<(ostream &os, const vector<T> &v){int n=v.size();rep(i,n)os<<v[i]<<(i==n-1?"":" ");return os;}

#define N 100010
vector<int> g[N];
ll v[N], dp[N], n;
bool used[N], ok = true;

void rec(int x){
	used[x] = true;
	vector<int> r;
	r.reserve(g[x].size());
	for(auto y: g[x]){
		if(used[y]) continue;
		rec(y);
		r.push_back(dp[y]);
	}
	if(r.empty()){
		dp[x] = v[x];
		return;
	}
	sort(all(r));
	ll s = 0;
	int m = r.size();
	rep(i, m) s += r[i];
	dp[x] = v[x] - (s-v[x]);
	ll t = (s-dp[x])/2;
	if(dp[x]<0||dp[x]>v[x]||t<0||t>min(s/2, s-r[m-1])||(s-dp[x])%2){
		ok = false;
	}
}

int main(){
	cin>>n;
	rep(i, n) cin>>v[i];
	rep(i, n-1){
		int x, y;
		cin>>x>>y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	if(n==2){
		cout<<(v[0]==v[1]?"YES":"NO")<<endl;
		return 0;
	}
	int u;
	rep(i, n){
		if(g[i].size()>1){
			u = i;
			break;
		}
	}
	rec(u);
	cerr<<dp[u]<<" "<<ok<<endl;
	cout<<(dp[u]==0&&ok?"YES":"NO")<<endl;
	return 0;
}
