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


int main(){	
	long long N;
	long long M;
	scanf("%lld",&N);
	scanf("%lld",&M);
	vector<vector<long long>> A(N-1+1,vector<long long>(M-1+1));
	vector<ll> piv(N);
	for(int i = 0 ; i <= N-1 ; i++){
		for(int j = 0 ; j <= M-1 ; j++){
			scanf("%lld",&A[i][j]);
			A[i][j]--;
		}
	}
	ll res = 1000;
	set<ll> s;
	rep(i, M) {
		map<ll, ll> m;
		rep(j, N) {
			m[A[j][piv[j]]]++;
		}
		ll maxp = -1, maxs = -1;
		rep(j, M) {
			if (maxs < m[j]) {
				maxs = m[j];
				maxp = j;
			}
		}
		s.insert(maxp);
		rep(j, N) {
			while (s.find(A[j][piv[j]]) != s.end()) {
				piv[j]++;
			}
		}
		res = min(res, maxs);
	}
	cout << res << endl;
	return 0;
}

