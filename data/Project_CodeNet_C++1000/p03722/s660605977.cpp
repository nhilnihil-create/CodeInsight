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
typedef vector<int> vi;
typedef array<int,2> a2;

const int N = 1e3 + 5;

vector<a2> g[N];

ll d[N];
int cnt[N];
bool in[N];
bool valid[N];

const ll inf = LLONG_MAX;
int n,m;

bool dfs(int x){
	if(in[x])return 0;	
	in[x] = 1;
	if(x == n-1)return 1;
	bool res = 0;
	for(a2 a:g[x])res |= dfs(a[0]);
	return res;
}

bool spfa(){
	fill(d,d+N,inf);
	memset(in,0,sizeof(in));
	queue<int> q;
	q.push(0);
	d[0] = 0;
	in[0] = 1;
	while(q.size()){
		int u = q.front();
		in[u] = 0;
		q.pop();
		for(a2 e:g[u]){
			if(!valid[e[0]])continue;
			if(d[u] + e[1] < d[e[0]]){
				d[e[0]] = d[u] + e[1];
				if(!in[e[0]]){
					in[e[0]] = 1;
					q.push(e[0]);
					++cnt[e[0]];
					if(cnt[e[0]] == n)return 0;	
				}
			}
		}
	}
	return 1;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	rep(i,0,m){
		int x,y,w;
		cin >> x >> y >> w;
		--x,--y;
		g[x].push_back(a2{y,-w});
	}
	rep(i,0,n){
		memset(in,0,sizeof(in));
		valid[i] = dfs(i);
	}
	bool val = spfa();
	if(val){
		cout << -d[n-1] << '\n';
	}
	else{
		cout << "inf" << '\n';
	}
}
