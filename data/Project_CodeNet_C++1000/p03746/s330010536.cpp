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

vector<vector<ll>> G(100001, vector<ll>());

vector<bool> used(100001);
vector<ll> l, r;

void concatl(ll n) {
	rep(i, G[n].size()) {
		ll m = G[n][i];
		if (!used[m]) {
			used[m] = true;
			l.emplace_back(m);
			concatl(m);
			break;
		}
	}
} 

void concatr(ll n) {
	rep(i, G[n].size()) {
		ll m = G[n][i];
		if (!used[m]) {
			used[m] = true;
			r.emplace_back(m);
			concatr(m);
			break;
		}
	}
} 

int main(){	
	long long N;
	long long M;
	scanf("%lld",&N);
	scanf("%lld",&M);
	vector<long long> A(M-1+1);
	vector<long long> B(M-1+1);
	for(int i = 0 ; i <= M-1 ; i++){
		scanf("%lld",&A[i]);
		scanf("%lld",&B[i]);
		A[i]--; B[i]--;
		G[A[i]].emplace_back(B[i]);
		G[B[i]].emplace_back(A[i]);
	}
	l.emplace_back(A[0]);
	r.emplace_back(B[0]);
	used[A[0]] = true;
	used[B[0]] = true;
	concatl(A[0]);
	concatr(B[0]);
	cout << l.size()+r.size() << endl;

	rep(i, l.size()) {
		cout << l[l.size()-1-i]+1 << " ";
	}
	rep(i, r.size()-1) {
		cout << r[i]+1 << " ";
	}
	cout << r[r.size()-1]+1 << endl;

	return 0;
}

