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
#define INF 1000000000000
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

void solve(long long N, long long T, vector<long long> A){
	ll cnt = 1, min = A[0], re = 0;
	repn(i, N-1) {
		if (A[i] < min) min = A[i];
		if (A[i] - min == re) {
			cnt++;
		}
		if (A[i] - min > re) {
			re = A[i] - min;
			cnt = 1;
		}
	}
	cout << cnt << endl;
}

int main(){	
	long long T;
	long long N;
	scanf("%lld",&N);
	vector<long long> A(N-1+1);
	scanf("%lld",&T);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&A[i]);
	}
	solve(N, T, A);
	return 0;
}

