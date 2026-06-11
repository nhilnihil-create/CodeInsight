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

int main(){	
	long long M;
	long long N;
	scanf("%lld",&N);
	vector<long long> X(N-1+1);
	scanf("%lld",&M);
	map<ll, ll> m;
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&X[i]);
		m[X[i]]++;
	}
	map<ll, ll> m1, m2;
	rep(i, 100001) {
		m1[i%M] += m[i]%2;
		m2[i%M] += m[i]-m[i]%2;
	}
	ll res = 0;
	rep(i, M/2+1) {
		// cout << i << ": " << m1[i] << " " << (M-i)%M << ": " << m1[(M-i)%M] << endl;
		// cout << i << ": " << m2[i] << " " << (M-i)%M << ": " << m2[(M-i)%M] << endl;
		if (i != (M-i)%M) {
			ll b1 = min(m1[i],m1[(M-i)%M]);
			// cout << i << ": " << m1[i] << " " << (M-i)%M << ": " << m1[(M-i)%M] << endl;
			// cout << i << ": " << m2[i] << " " << (M-i)%M << ": " << m2[(M-i)%M] << endl;
			res += b1;
			m1[i] -= b1;
			m1[(M-i)%M] -= b1;
		} else {
			ll b1 = m1[i]/2;
			res += b1;
			m1[i] -= b1;
			// cout << i << ": " << m1[i] << " " << (M-i)%M << ": " << m1[(M-i)%M] << endl;
			// cout << i << ": " << m2[i] << " " << (M-i)%M << ": " << m2[(M-i)%M] << endl;
		}
		// cout << i << ": " << m1[i] << " " << (M-i)%M << ": " << m1[(M-i)%M] << endl;
		// cout << i << ": " << m2[i] << " " << (M-i)%M << ": " << m2[(M-i)%M] << endl;
		if (i != (M-i)%M && m1[i] > 0) {
			ll b2 = min(m1[i],m2[(M-i)%M]);
			res += b2;
			m1[i] -= b2;
			m2[(M-i)%M] -= b2;
		}
		if (i != (M-i)%M && m1[(M-i)%M] > 0) {
			ll b2 = min(m1[(M-i)%M],m2[i]);
			res += b2;
			m1[(M-i)%M] -= b2;
			m2[i] -= b2;
		}
		// cout << i << ": " << m1[i] << " " << (M-i)%M << ": " << m1[(M-i)%M] << endl;
		// cout << i << ": " << m2[i] << " " << (M-i)%M << ": " << m2[(M-i)%M] << endl;
	}
	rep(i, M) {
		res += m2[i]/2;
	}
	cout << res << endl;
	return 0;
}

