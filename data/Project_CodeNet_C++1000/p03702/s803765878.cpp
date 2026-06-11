#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define ppb pop_back
#define umax(x,y) x=max(x,y)
#define umin(x,y) x=min(x,y)
#define ll long long
#define ii pair<int,int>
#define iii pair<int,ii>
#define iiii pair<ii,ii>
#define sz(x) ((int) x.size())
#define orta ((bas+son)>>1)
#define all(x) x.begin(),x.end()
#define dbgs(x) cerr<<(#x)<<" --> "<<(x)<<" "
#define dbg(x) cerr<<(#x)<<" --> "<<(x)<<endl;getchar()
#define pw(x) (1ll<<(x))
#define inf 2005000
#define MOD 1000000007
#define N 100005
#define M 1000005
#define LOG 60
#define KOK 4000000
using namespace std;

int n,a,b;
ll ar[N],ar2[N];

bool ok(ll val) {

	ll tot=val*b;

	for(int i=1;i<=n;i++) ar2[i]=ar[i]-tot;

	ll cnt=0;

	for(int i=1;i<=n;i++) {

		if(ar2[i]>0) cnt+=(ar2[i]+(a-b)-1)/(a-b);

	}

	return cnt<=val;

} 

int main() {

	//freopen("input.txt","r",stdin);

	scanf("%d %d %d",&n,&a,&b);

	for(int i=1;i<=n;i++) {

		scanf("%lld",&ar[i]);

	}

	ll bas=0,son=100000000000000/max(a,b);

	while(bas<=son) {

		if(ok(orta)) son=orta-1;
		else bas=orta+1;

	}

	printf("%lld",bas);

}