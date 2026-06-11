#include <bits/stdc++.h>
using namespace std;
#define int long long
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
#define ZIP(v) sort(all(v)),UNIQUE(v)
#define ADD(a, b) a = (a + b) % mod
#define MUL(a, b) a = (a * b) % mod
#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n) repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define dmp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define fi first
#define se second
typedef pair<int,int> P;
typedef pair<int, P> PP;
typedef vector<int> vi;
const int inf = 1e9+7;
const int INF = 1e18+7;
//26

int a[200000], sum[400000];
signed main(){
	int n, m, s = 0;
	scanf("%lld%lld", &n, &m);
	rep(i,n)scanf("%lld",&a[i]);
	rep(i,n-1){
		int l = a[i], r = a[i+1];
		if(l > r)r += m;
		if(l+2 <= r){
			sum[l+2]++;
			sum[r+1] -= (r-(l+1))+1;
			sum[r+2] += (r-(l+1));
		}
		s += r-l;
	}
	rrep(i,2*m)sum[i] += sum[i-1];
	rrep(i,2*m)sum[i] += sum[i-1];
	
	int ans = 0;
	rrep(i,m){
		chmax(ans, sum[i]+sum[i+m]);
	}
	printf("%lld\n", s-ans);
	return 0;
}



