#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> adj(n+1, 0);
	for(int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		++adj[a];
		++adj[b];
	}
	for(int i = 1; i <= n; ++i){
		cout << adj[i] << "\n";
	}

	return 0;
}
