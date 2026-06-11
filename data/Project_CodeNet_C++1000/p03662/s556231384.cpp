#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
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

vector<ll> G[100001];
vector<ll> bw(100001,-1);

int main(){	
	long long N;
	scanf("%lld",&N);
	for(int i = 0 ; i <= (N-1)-1 ; i++){
		ll a,b;
		scanf("%lld",&a);
		--a;
		scanf("%lld",&b);
		--b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	queue<P> que;
	que.push(P(0, 0));
	que.push(P(N-1, 1));
	while(!que.empty()) {
		ll f = que.front().first, s = que.front().second;
		if (bw[f] == -1) bw[f] = s;
		for (auto x : G[f]) {
			// cout << f << " " << s << " " << x << endl;
			if (bw[x] == -1) que.push(P(x, s));
		}
		que.pop();
	}
	ll bc = 0;
	rep(i, N) {
		// cout << bw[i];
		if (bw[i] == 0) bc++;
	}
	// cout << endl;
	if (bc > N/2) cout << "Fennec" << endl; else cout << "Snuke" << endl;
	return 0;
}

