#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define all(c) c.begin(), c.end()
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define gadd(x,y) x=add(x,y)
#define gmul(x,y) x=mul(x,y)
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int N = 1e5 + 5;
int p[N], d[N];
vector<int> nxt[N];

void dfs(int u, int depth=0){
	d[u] = depth;
	for(int v:nxt[u]){
		dfs(v,depth+1);
	}
}

set<pii> s;

void clear(int u){
	for(int v:nxt[u]){
		clear(v);
	}
	nxt[u].clear();
	s.erase({d[u],u});
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n,k;
	cin >> n >> k;
	int ans = 0;
	rep(i,0,n){cin >> p[i];--p[i];}
	if(p[0] != 0){
		p[0] = 0;	
		++ans;
	}
	rep(i,1,n)nxt[p[i]].push_back(i);
	dfs(0);
	rep(i,1,n)s.insert({d[i], i});
	while(s.size() && s.rbegin()->first > k){
		int i = s.rbegin()->second;
		int cur = k-1;
		while(cur--)i = p[i];
		clear(i);
		++ans;
	}
	cout << ans << '\n';
}
