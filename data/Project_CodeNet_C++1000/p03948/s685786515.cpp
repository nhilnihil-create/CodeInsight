#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define pb push_back
#define pf push_front
#define fi first
#define se second

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, P> PP;

struct edge {
	int to,cost;
	edge(int t,int c):to(t),cost(c) {}
};

int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int ddx[]={1,1,1,0,-1,-1,-1,0},ddy[]={1,0,-1,-1,-1,0,1,1};

//-----------------------------------------------------------------------------

int n;
ll a[100001],t;
ll ma[100001],dif;
int cnt;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>n>>t;
	REP(i,n) cin>>a[i];

	for(int i=n-1;i>=0;i--) ma[i]=max(ma[i+1],a[i]);

	REP(i,n-1) {
		if(a[i]+dif==ma[i+1]) cnt++;
		else if(a[i]+dif<ma[i+1]) {
			dif=ma[i+1]-a[i];
			cnt=1;
		}
	}

	cout<<cnt<<endl;

	return 0;
}
