#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF LLONG_MAX-1
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(long long i=0;i<x;i++)
#define repn(i,x) for(long long i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<pair<string,P> >vec;
// vector<vector<int>> data(3, vector<int>(4));

void solve(long long N, long long x, vector<long long> a){
	vector<ll> mincost(N, INF);
	ll res = INF;
	rep(i,N) {
		ll now = 0;
		rep(j,N) {
			mincost[j] = min(mincost[j], a[(j+N-i)%N]);
		}
		rep(j,N) {
			now += mincost[j];
		}
		now += x*i;
		res = min(res, now);
	}
	cout << res << endl;
}

int main(){	
	long long x;
	long long N;
	scanf("%lld",&N);
	vector<long long> a(N-1+1);
	scanf("%lld",&x);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&a[i]);
	}
	solve(N, x, a);
	return 0;
}

