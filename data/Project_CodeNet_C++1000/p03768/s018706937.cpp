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

const int N = 1e5 + 5;
vi g[N];
int col[N];
bool vis[N][11];

void bfs(int v, int d, int c){
	if(vis[v][d])return;
	queue<pii> q;
	q.push({v,d});
	while(q.size()){
		int u = q.front().first;	
		int dist = q.front().second;	
		q.pop();
		if(!vis[u][dist]){
			vis[u][dist] = 1;		
			if(col[u] == 0)col[u] = c;
			if(dist){
				for(int v:g[u]){
					q.push({v,dist-1});	
				}
			}
		}
	}
}


int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n,m,q;
	cin >> n >> m;
	rep(i,0,m){
		int x,y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cin >> q;
	vector<array<int,3>> v(q);
	rep(i,0,q)cin >> v[i][0] >> v[i][1] >> v[i][2];
	for(int i = q-1;i >= 0;--i){
		bfs(v[i][0], v[i][1], v[i][2]);
	}
	rep(i,1,n+1){
		cout << col[i] << '\n';	
	}
}
