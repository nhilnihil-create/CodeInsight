#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<int, int> P;
typedef pair<int, P> E;
#define MOD (1000000007ll)
#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a += b;
	if(a>MOD){
		a -= MOD;
	}
}

int a[2020],b[2020],d[2020],n,k,tmp,ans=INF;
vector<int> g[2020];
queue<int> q;

void solve(int x, int y){
	int u,v,j;
	fill(d,d+2020,-1);
	d[x] = k/2;
	q.push(x);
	if(k%2){
		d[y] = k/2;
		q.push(y);
	}
	tmp = n;
	while(!q.empty()){
		u = q.front();
		q.pop();
		--tmp;
		for(j=(g[u].l_ength()-1); j>=0; --j){
			v = g[u][j];
			if(d[v]>=0){
				continue;
			}
			if(d[u]){
				d[v] = d[u]-1;
				q.push(v);
			}
		}
	}
	ans = min(tmp,ans);
}

int main(void){
	int i;
	cin >> n >> k;
	for(i=1; i<n; ++i){
		cin >> a[i] >> b[i];
		--a[i]; --b[i];
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	}
	for(i=k%2; i<n; ++i){
		solve((k%2)?a[i]:i,(k%2)?b[i]:(-1));
	}
	cout << ans << endl;
	return 0;
}
