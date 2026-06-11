#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define umax(x,y) x=max(x,y)
#define umin(x,y) x=min(x,y)
#define ll long long 
#define ii pair<int,int>
#define iii pair<int,ii>
#define iiii pair<ii,ii>
#define sz(x) ((int) x.size())
#define orta ((bas+son)/2)
#define all(x) x.begin(),x.end()
#define pw(x) (1<<(x))
#define inf 1000000005
#define MOD 924844033 
#define N 100005
#define M 1000003
#define LOG 20
#define KOK 250
#define EPS 0.0000001
using namespace std;

int n,k,ans;
vector<int> v[N];

int dfs(int node,int ata) {

	int cd=0;

	for(int i:v[node]) {

		umax(cd,dfs(i,node)+1);

	}

	if(cd>=k-1 && (ata!=1 && node!=1)) {

		ans++;
		cd=-1;

	}

	return cd;

}

int main() {

	scanf("%d %d",&n,&k);

	for(int i=1;i<=n;i++) {

		int x;

		scanf("%d",&x);

		if(i==1) {

			ans+=(x!=1);
			x=1;

			continue ;

		}

		v[x].pb(i);

	}

	dfs(1,0);

	printf("%d",ans);

}