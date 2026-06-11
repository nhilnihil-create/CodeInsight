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

long long A;
long long N;
long long B;
vector<long long> h(100001);

// c回の爆発で全員倒せなければtrue
bool C1(long long c) {
	ll res = 0;
	rep(i, N) {
		ll r = h[i]-B*c;
		if (r > 0) res += (r+(A-B-1))/(A-B);
	}
	return res > c;
}

int main(){	
	scanf("%lld",&N);
	scanf("%lld",&A);
	scanf("%lld",&B);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&h[i]);
	}

	long long lb = 0, ub = 0;
	rep(i, N) {
		ub += (h[i]+B-1)/B;
	}
	++ub;
	while (ub - lb > 1) {
		long long mid = (lb + ub) / 2;
		if (C1(mid)) lb = mid;
		else ub = mid;
	}
	cout << ub << endl;
	return 0;
}

