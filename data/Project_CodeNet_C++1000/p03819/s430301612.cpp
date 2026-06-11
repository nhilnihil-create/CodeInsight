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
#define inf 1000000000
#define MOD 1000000007 
#define N 100005
#define M 1000000
#define LOG 20
#define KOK 300
#define EPS 0.0000001
using namespace std;

int n,m;
int ans[N];
int f[N<<1];
vector<ii> v[N<<1];

int get(int x) {

	int res=0;

	for(int i=x;i>=1;i-=i&-i) res+=f[i];

	return res;

}

void up(int x) {

	for(int i=x;i<=m+m;i+=i&-i) f[i]++;

}

int main() {

	scanf("%d %d",&n,&m);

	for(int i=1;i<=n;i++) {

		int l,r;

		scanf("%d %d",&l,&r);

		v[r].pb({l,1});

	}

	for(int i=1;i<=m;i++) {

		for(int j=i;j<=m+m;j+=i) {

			v[j].pb({j-i,0});

		}

	}

	for(int i=1;i<=m+m;i++) {

		sort(all(v[i]),[](ii a,ii b){return a.nd<b.nd;});

		for(auto x:v[i]) {

			if(x.nd) {

				up(x.st);

			}
			else {

				ans[i-x.st]+=get(i-1)-get(x.st);

			}

		}

	}

	for(int i=1;i<=m;i++) printf("%d\n",n-ans[i]);

}	