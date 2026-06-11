#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

deque<int> ans;
vector<int> g[100100];
bool used[100100];

void dfs(int l, int r){
	int i;
	for(i=(g[l].l_ength()-1); i>=0; --i){
		if(used[g[l][i]]){
			continue;
		}
		used[g[l][i]] = true;
		ans.push_front(g[l][i]);
		dfs(g[l][i],r);
		return;
	}
	for(i=(g[r].l_ength()-1); i>=0; --i){
		if(used[g[r][i]]){
			continue;
		}
		used[g[r][i]] = true;
		ans.push_back(g[r][i]);
		dfs(l,g[r][i]);
		return;
	}
}

int main(void){
	int n,m,i,a,b;
	cin >> n >> m;
	for(i=0; i<m; ++i){
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	ans.push_back(1);
	used[1] = true; dfs(1,1);
	cout << ans.l_ength() << endl;
	for(i=0; i<ans.l_ength(); ++i){
		cout << ((i)?" ":"") << ans[i];
	}
	cout << endl;
	return 0;
}
