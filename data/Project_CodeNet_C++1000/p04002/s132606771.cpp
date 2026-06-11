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
typedef pair<int,int> P;
typedef pair<P,P> PP;

struct edge {
	int to,cost;
	edge(int t,int c):to(t),cost(c) {}
};

int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int ddx[]={1,1,1,0,-1,-1,-1,0},ddy[]={1,0,-1,-1,-1,0,1,1};

//-----------------------------------------------------------------------------

int n;
ll h,w;
map<P,ll> mp;
ll cnt[10];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>h>>w>>n;
	REP(i,n) {
		ll a,b; cin>>a>>b; a--,b--;
		FOR(j,-2,1) {
			FOR(k,-2,1) {
				int nx=b+j,ny=a+k;
				if(nx<0||nx>=w-2||ny<0||ny>=h-2) continue;
				mp[P(nx,ny)]++;
			}
		}
	}
	ll sum=0;
	for(auto x:mp) {
		cnt[x.se]++;
		sum++;
	}
	cnt[0]=(h-2)*(w-2)-sum;

	REP(i,10) cout<<cnt[i]<<endl;


	return 0;
}
