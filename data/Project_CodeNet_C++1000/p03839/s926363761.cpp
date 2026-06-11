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
#define INF 1000000000
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

void solve(long long N, long long K, vector<long long> a){
	ll suma[N], sumb[N];
	suma[0] =  max(a[0],0LL);
	sumb[0] =  a[0];
	repn(i,N-1) {
		suma[i] = suma[i-1] + max(a[i],0LL);
		sumb[i] = sumb[i-1] + a[i];
	}
	// rep(i,N) {
	// 	cout << suma[i] << endl;
	// }
	ll res = 0;
	rep(i,N-K+1) {
		ll now = suma[N-1];
		now -= suma[i+K-1];
		if (i-1 >= 0) now += suma[i-1];
		ll borw = sumb[i+K-1];
		if (i-1 >= 0) borw -= sumb[i-1];
		now += max(borw, 0LL);
		res = max(res, now);
	}
	cout << res << endl;
}

int main(){	
	long long K;
	long long N;
	scanf("%lld",&N);
	vector<long long> a(N-1+1);
	scanf("%lld",&K);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&a[i]);
	}
	solve(N, K, a);
	return 0;
}

