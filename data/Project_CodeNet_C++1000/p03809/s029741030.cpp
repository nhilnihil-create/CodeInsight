#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define ppb pop_back
#define umax(x,y) x=max(x,y)
#define umin(x,y) x=min(x,y)
#define ll long long
#define ii pair<int,int>
#define iii pair<ii,int>
#define iiii pair<ii,ii>
#define sz(x) ((int) x.size())
#define orta ((bas+son)>>1)
#define all(x) x.begin(),x.end()
#define dbgs(x) cerr<<(#x)<<" --> "<<(x)<<" "
#define dbg(x) cerr<<(#x)<<" --> "<<(x)<<endl;getchar()
#define pw(x) (1<<(x))
#define inf 2000000000
#define MOD 998244353
#define N 100005
#define MAX 5000000
#define LOG 100
#define KOK 333
using namespace std;

int a[N];
int x,y,n;
vector<int> v[N];

void print(bool ver) {

	printf(ver?"YES":"NO");

	exit(0);

}

ll obtain(vector<ll>&chs) {

	if(!sz(chs)) return 0;

	ll mt=0,re=chs[0];

	for(int i=1;i<sz(chs);i++) {

		ll nm=min(chs[i],re);

		chs[i]-=nm;
		re-=nm;

		ll cm=min(chs[i]/2,mt);

		chs[i]-=cm*2;
		re+=chs[i];
		mt+=cm+nm;

	}

	return mt*2;

}

ll dfs(int node,int ata) {

	if(sz(v[node])==1) return a[node];

	ll sum=0;

	vector<ll> chs;

	for(int i:v[node]) {

		if(i==ata) continue ;

		ll add=dfs(i,node);

		sum+=add;

		chs.pb(add);

	}

	ll del=(sum-a[node])*2;

	if(del<0 || obtain(chs)<del) print(false);

	return sum-del;

}

int main() {

	//freopen("input.txt","r",stdin);

	scanf("%d",&n);

	for(int i=1;i<=n;i++) scanf("%d",a+i);

	if(n==2) print(a[1]==a[2]);

	for(int i=1;i<n;i++) {

		scanf("%d %d",&x,&y);

		v[x].pb(y);
		v[y].pb(x);

	}

	int root=1;

	for(int i=1;i<=n;i++) if(sz(v[i])>1) root=i;

	print((dfs(root,0)==0));
 
}