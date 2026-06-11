#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m;
	cin >> n >> m;
	vector<vector<pair<long long,long long>>> graph(n);
	for(int i=0;i<m;i++){
		long long a,b,c;
		cin >> a >> b >> c;
		a--;
		b--;
		c *= (-1);
		graph[a].push_back({b,c});
	}
	vector<long long> dist(n,1LL<<60);
	dist[0] = 0;
	auto bf = [&](int x){
		for(int i=0;i<x;i++){
			for(int j=0;j<n;j++){
				for(auto p:graph[j]){
					if(dist[p.first] > dist[j] + p.second){
						dist[p.first] = dist[j] + p.second;
					}
				}
			}
		}
	};
	bf(n-1);
	long long ans = dist[n-1];
	bf(n);
	if(ans != dist[n-1]) cout << "inf" << endl;
	else cout << -ans << endl;
}
