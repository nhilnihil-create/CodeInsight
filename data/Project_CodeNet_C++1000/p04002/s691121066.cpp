#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
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


int main(){	
	long long W;
	long long N;
	long long H;
	scanf("%lld",&H);
	scanf("%lld",&W);
	scanf("%lld",&N);
	vector<long long> a(N-1+1);
	vector<long long> b(N-1+1);
	set<P> s;
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&a[i]);
		scanf("%lld",&b[i]);
		s.insert(P(a[i],b[i]));
	}
	vector<ll> res(10);
	for (auto x : s) {
		// cout << x.first << " " << x.second  << endl;
		for (ll i = x.first-1; i <= x.first+1; i++) {
			for (ll j = x.second-1; j <= x.second+1; j++) {
				if (i <= 1 || i >= H || j <= 1 || j >= W) continue;
				ll cnt = 0;
				for (ll k = i-1; k <= i+1; k++) {
					for (ll l = j-1; l <= j+1; l++) {
						if (s.find(P(k,l)) != s.end()) cnt ++;
					}
				}
				// cout << i << " " << j << " :" << cnt << endl; 
				if (cnt >= 0) res[cnt]++;
			}
		}
	}
	repn(i, 9) {
		res[i] /= i;
	}
	res[0] = (H-2)*(W-2);
	repn(i, 9) {
		res[0] -= res[i];
	}
	rep(i, 10) {
		cout << res[i] << endl;
	}
	return 0;
}

