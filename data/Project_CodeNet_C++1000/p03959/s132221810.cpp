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
// vector<vector<int>> data(3, vector<int>(4));

void solve(long long N, vector<long long> T, vector<long long> A){
	bool fixt[N], fixa[N];
	rep(i, N) {
		if (i == 0 || T[i] > T[i-1]) fixt[i] = true; else fixt[i] = false;
 	}
	rep(i, N) {
		if (i == N-1 || A[i] > A[i+1]) fixa[i] = true; else fixa[i] = false;
 	}
	ll res = 1;
	rep(i, N) {
		if (!fixt[i] && !fixa[i]) res = res*min(T[i], A[i])%mod;
		if (fixt[i] && !fixa[i] && T[i] > A[i]) res = 0;
		if (!fixt[i] && fixa[i] && T[i] < A[i]) res = 0;
		if (fixt[i] && fixa[i] && T[i] != A[i]) res = 0;
		// cout << i << " " << res << endl;
	}
	cout << res << endl;
}

int main(){	
	long long N;
	scanf("%lld",&N);
	vector<long long> A(N-1+1);
	vector<long long> T(N-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&T[i]);
	}
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&A[i]);
	}
	solve(N, T, A);
	return 0;
}

