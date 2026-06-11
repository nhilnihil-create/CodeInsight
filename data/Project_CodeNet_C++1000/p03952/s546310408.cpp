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

void solve(long long N, long long x){
	if (1 < x && x < 2*N-1) {
		cout << "Yes" << endl;
		queue<ll> que;
		repn(i,2*N-1) {
			if (i != 1 && i != 2*N-1 && i != x) {
				que.push(i);
			}
		}
		rep(i,N-2) {
			if (!que.empty()) {
				cout << que.front() << endl;
				que.pop();
			}
		}
		cout << 1 << endl;
		cout << x << endl;
		cout << 2*N-1 << endl;
		rep(i,N-2) {
			if (!que.empty()) {
				cout << que.front() << endl;
				que.pop();
			}
		}
	} else {
		cout << "No" << endl;
	}
}

int main(){	
	long long x;
	long long N;
	scanf("%lld",&N);
	scanf("%lld",&x);
	solve(N, x);
	return 0;
}

