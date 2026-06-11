#include <bits/stdc++.h>

using namespace std;

struct dat {
	int a,b,c;
};

int G[100][100];

int main() {
	int n,m; cin >> n >> m;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			G[i][j]=1e9;
	for(int i=0;i<n;++i) G[i][i]=0;
	vector<dat> abc(m);
	for(auto &e:abc) {
		cin >> e.a >> e.b >> e.c;
		--e.a; --e.b;
		G[e.a][e.b]=G[e.b][e.a]=e.c;
	}
	for(int k=0;k<n;++k)
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
	int ans=0;
	for(auto e:abc)
		if(G[e.a][e.b]<e.c) ++ans;
	cout << ans << endl;
	
	return 0;
}