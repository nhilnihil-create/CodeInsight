#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define f first
#define s second
#define MAXN 100010

priority_queue<pi,vpi,greater<pi>> pq;
vi V[MAXN];
ll N,M;
ll W,ans;
ll A[MAXN];
ll save;

int main(){
	cin>>N>>M;
	for (ll i=1;i<=N;++i){
		cin>>A[i];
	}
	for (ll i=1;i<N;++i){
		ll w = (A[i+1]+M-A[i])%M;
		W += w;
		if (A[i+1] < A[i]){
			save += (M-A[i]);
			pq.push(mp(A[i+1], A[i]));
			// cout<<"Push "<<A[i]<<' '<<A[i+1]<<'\n';
		}
		V[A[i]].pb(A[i+1]);
	}
	ll sv = 0;
	// cout<<"Save 1 "<<W-save<<'\n';
	sv = max(sv,save);
	for (ll i=2;i<=M;++i){
		// cout<<pq.top().f<<'\n';
		while(SZ(pq) && pq.top().f == i-1){
			pi p = pq.top();pq.pop();
			// cout<<"Remove "<<p.s<<' '<<p.f<<'\n';
			save -= (p.f+M-p.s)%M; 
			++save;
		}
		save += SZ(pq);
		for (auto x:V[i-1]){
			if(i-1>x)pq.push(mp(x+M,i-1));
			else pq.push(mp(x,i-1));
			// cout<<i-1<<' '<<x<<'\n';
		}
		// cout<<"Save "<<i<<' '<<W-save<<'\n';
		sv = max(sv,save);
	}
	cout<<W-sv<<'\n';
}