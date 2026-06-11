#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 101, MAX_M = 1003;
int n, m;
int dist[MAX_N][MAX_N];
int a[MAX_M],b[MAX_M],c[MAX_M];

void init()
{
	memset(dist, 0x3f, sizeof(dist));
	for(int i=0;i<n;++i) dist[i][i]=0;
}

void add_edge(int from, int to, int cost)
{
	dist[from][to]=dist[to][from]=cost;
}

void solve()
{
	for(int k=0;k<n;++k){
		for(int i=0;i<n;++i)for(int j=0;j<n;++j){
			dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		}
	}
	int ans = 0;
	for(int i=0;i<m;++i){
		int from = a[i], to = b[i], cost = c[i];
		bool need=true;
		for(int i=0;i<n;++i)if(i!=from && i!=to){
			if(dist[from][i]+dist[i][to] < cost){
				need=false;
				break;
			}
		}
		if(!need)ans++;
	}
	cout << ans << '\n';
}

int main()
{
	cin >> n >> m;
	init();
	for(int i=0;i<m;++i){
		cin >> a[i] >> b[i] >> c[i];
		add_edge(--a[i],--b[i],c[i]);
	}
	solve();
	return 0;
}