#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; ++i)
#define FOR(i,n,m) for(long long i=n; i<m; ++i)
#define DUMP(n,a) for(long long dump=0; dump<n; ++dump) { cout<<a[dump]; if(dump!=n-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll w,h;
	cin>>w>>h;
	priority_queue<ll,vector<ll>,greater<ll>> p;
	priority_queue<ll,vector<ll>,greater<ll>> q;
	REP(i,w) {
		ll n;
		cin>>n;
		p.push(n);
	}
	REP(i,h) {
		ll n;
		cin>>n;
		q.push(n);
	}
	ll pc=0,qc=0;
	__int128 ret=0;
	while(!p.empty()||!q.empty()) {
		if(q.empty()||(!p.empty()&&p.top()<q.top())) {
			ret+=p.top()*(h+1-qc);
			p.pop();
			++pc;
		} else {
			ret+=q.top()*(w+1-pc);
			q.pop();
			++qc;
		}
	}
	cout<<(ll)ret<<endl;
}
