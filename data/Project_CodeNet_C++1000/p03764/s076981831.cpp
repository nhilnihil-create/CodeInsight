#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define ppb pop_back
#define ppf pop_front
#define umax(x,y) x=max(x,y)
#define umin(x,y) x=min(x,y)
#define ll long long
#define ii pair<int,int>
#define iii pair<ii,int>
#define iiii pair<ii,ii>
#define sz(x) ((int) x.size())
#define orta ((bas+son)/2)
#define all(x) x.begin(),x.end()
#define dbgs(x) cerr<<(#x)<<" --> "<<(x)<<" "
#define dbg(x) cerr<<(#x)<<" --> "<<(x)<<endl;getchar()
#define pw(x) (1ll<<(x))
#define inf 1000000000
#define MOD 1000000007
#define N 100005
#define M 10000001
#define LOG 16
#define KOK 650
#define EPS 0.00001
using namespace std;

int n,m,x[N],y[N];

int main() {

	//freopen("input.txt","r",stdin);

	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin>>n>>m;

	for(int i=1;i<=n;i++) cin>>x[i];

	for(int i=1;i<=m;i++) cin>>y[i];

	int ax=0,ay=0;
	int s=0;

	for(int i=1;i<=n;i++) {

		ax=(ax+(ll)(i-1)*x[i]-s)%MOD;

		s=(s+x[i])%MOD;

	}

	s=0;

	for(int i=1;i<=m;i++) {

		ay=(ay+(ll)(i-1)*y[i]-s)%MOD;

		s=(s+y[i])%MOD;

	}

	cout<<(ll)ax*ay%MOD;
}

