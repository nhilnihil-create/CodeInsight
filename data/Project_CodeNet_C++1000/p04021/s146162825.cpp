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
#define INF 10000000000000
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

int main(){	
	long long N;
	scanf("%lld",&N);
	vector<ll> A(N), B(N);
	ll res = 0;
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&A[i]);
		B[i] = A[i];
	}
	map<ll, ll> m;
	SORT(B);
	rep(i, N) {
		m[B[i]] = i;
	}
	rep(i, N) {
		if (i%2 == 0 && abs(m[A[i]] - i)%2 == 1) res++;
	}
	
	cout << res << endl;
	
	return 0;
}

