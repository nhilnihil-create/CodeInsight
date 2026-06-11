#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<int, int> P;
typedef pair<ll, P> E;
#define MOD (998244353ll)
#define l_ength size
#define EPS (1e-10)

void add_mod(ll &a, ll b){
	a += b;
	a %= MOD;
}

void mul_mod(ll &a, ll b){
	a *= b;
	a %= MOD;
}

vector<int> g[123456];
int dz[123456],dn[123456];
queue<int> q;

int main(void){
	int n,i,a,b,p,cnt=0;
	fill(dz,dz+123456,INF);
	fill(dn,dn+123456,INF);
	cin >> n;
	for(i=1; i<n; ++i){
		cin >> a >> b; --a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dz[0] = 0; q.push(0);
	while(!q.empty()){
		p = q.front();
		q.pop();
		for(i=(g[p].l_ength()-1); i>=0; --i){
			if(dz[g[p][i]] == INF){
				dz[g[p][i]] = dz[p] + 1;
				q.push(g[p][i]);
			}
		}
	}
	q.push(n-1); dn[n-1] = 0;
	while(!q.empty()){
		p = q.front();
		q.pop();
		for(i=(g[p].l_ength()-1); i>=0; --i){
			if(dn[g[p][i]] == INF){
				dn[g[p][i]] = dn[p] + 1;
				q.push(g[p][i]);
			}
		}
	}
	for(i=0; i<n; ++i){
		if(dz[i] > dn[i]){
			--cnt;
		}else{
			++cnt;
		}
	}
	cout << ((cnt>0)?"Fennec":"Snuke") << endl;
	return 0;
}
