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

void solve(long long N, vector<long long> p){
	vector<ll> a(N), b(N);
	rep(i,N) {
		a[i] = (i+1)*N;
		b[i] = (N-i)*N;
	}
	rep(i,N) {
		a[p[i]] += i;
	}
	rep(i,N-1) {
		cout << a[i] << " ";
	}
	cout << a[N-1] << endl;
	rep(i,N-1) {
		cout << b[i] << " ";
	}
	cout << b[N-1] << endl;
}

int main(){	
	long long N;
	scanf("%lld",&N);
	vector<long long> p(N-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&p[i]);
		p[i]--;
	}
	solve(N, p);
	return 0;
}

