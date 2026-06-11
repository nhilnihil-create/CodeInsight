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

void solve(long long N, vector<long long> A){
	ll k = 0;

	rep(i, N) {
		k += A[i];
	}
	// cout << k << endl;
	bool flg = true;
	if (k * 2 % (N * (N + 1)) != 0) flg = false;
	k = k * 2 / (N * (N + 1));
	// cout << k << endl;
	ll cnt = 0;
	
	rep(i, N) {
		ll e =  -1 * (A[(i+1)%N] - A[i%N] - k);
		// cout << i << " " << e << endl;
		if (e < 0 || e % N != 0) {
			flg = false;
			break;
		}
		cnt += e / N;
	}
	if (cnt == k && flg) cout << "YES" << endl; else cout << "NO" << endl;
}

int main(){	
	long long N;
	scanf("%lld",&N);
	vector<long long> A(N-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&A[i]);
	}
	solve(N, A);
	return 0;
}

