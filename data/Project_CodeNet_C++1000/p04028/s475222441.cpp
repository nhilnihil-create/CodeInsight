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

#define N 5010
ll dp[2][N];

ll inv[N], fact[N], ifact[N];
 
void init_fact(ll n = N){
    inv[1] = 1;
    for(int i = 2; i < n;i++) inv[i] = inv[mod%i] * (mod - mod/i) % mod;
	fact[0] = ifact[0] = 1;
	for(int i = 1; i < n; i++){
		fact[i] = (fact[i-1]*i)%mod;
		ifact[i]=(ifact[i-1]*inv[i])%mod;
	}
}

ll pow_mod(ll a, ll r, ll m){
	ll x = 1;
	while(r){
		if(r&1) (x*=a)%=m;
		(a*=a)%=m;
		r>>=1;
	}
	return x;
}

int main(){
	int n;
	string s;
	cin>>n>>s;
	init_fact();
	dp[0][0] = pow_mod(inv[2], s.size(), mod);
	rep(i, n){
		int t = i%2;
		fill(dp[!t], dp[!t]+N, 0);
		rep(j, n){
			(dp[!t][j+1]+=2*dp[t][j])%=mod;
			(dp[!t][max(j-1, 0)]+=dp[t][j])%=mod;
		}
	}
	cout<<dp[n%2][s.size()]<<endl;
	return 0;
}
