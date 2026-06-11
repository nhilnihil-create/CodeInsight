#include <bits/stdc++.h>

using namespace std;

vector <vector <int> >g;

int calc(int pre, int u){
	int s=0;
	for(int i=0;i<g[u].size();++i){
		if(pre!=g[u][i]) s^=calc(u, g[u][i]);
	}
	return s+1;
}

int main(){
	int n;
	cin >> n;
	g=vector <vector <int> >(n);
	for(int i=0;i<n-1;++i){
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int r=0;
	for(int i=0;i<g[0].size();++i){
		r^=calc(0, g[0][i]);
	}
	if(r==0) cout << "Bob" << endl;
	else cout << "Alice" << endl;
}