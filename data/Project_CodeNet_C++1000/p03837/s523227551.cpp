#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define all(c) c.begin(), c.end()
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int N = 100 + 5;

int d[N][N], g[N][N];

const int inf = 1e9;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	vector<pii> e;
	rep(i,0,n)rep(j,0,n)d[i][j] = d[j][i] = (i == j ? 0 :inf);
	rep(i,0,m){
		int x,y,w;
		cin >> x >> y >> w;
		--x,--y;
		d[x][y] = d[y][x] = w;
		g[x][y] = g[y][x] = w;
		e.emplace_back(x,y);
	}
	rep(k,0,n){
		rep(i,0,n){
			rep(j,0,n){
				gmin(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int cnt = 0;
	for(pii p:e){
		int x = p.first;
		int y = p.second;
		bool bad = 1;
		rep(i,0,n){
			rep(j,0,n){
				if(d[i][j] == d[i][x] + d[y][j] + g[x][y])bad = 0;
			}
		}
		cnt += bad;
	}
	cout << cnt << '\n';
}
