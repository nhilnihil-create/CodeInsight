#include <bits/stdc++.h>
using namespace std;

long long n, k, a, b, r, mini = LLONG_MAX, d[2001];
vector<long long> adj[2001];
vector<pair<long long, long long> > edg;
void distance(long long node){
	for(int i = 0; i < adj[node].size(); i++){
		if(d[adj[node][i]] == -1 || d[adj[node][i]] > d[node]+1){
			d[adj[node][i]] = d[node]+1;
			distance(adj[node][i]);
		}
	}
}

int main(){
	cin >> n >> k;
	for(int i = 0; i < n-1; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		edg.push_back(make_pair(a, b));
	}
	if(k % 2 == 0){
	    for(int i = 1; i <= n; i++){
		    memset(d, -1, sizeof(d));
		    d[i] = 0;
		    distance(i);
		    r = 0;
			for(int j = 1; j <= n; j++){
				if(d[j] > k/2) r++;
			}
			mini = min(mini, r);
		}
	} else {
	    for(int i = 0; i < n-1; i++){
	        memset(d, -1, sizeof(d));
	        d[edg[i].first] = d[edg[i].second] = 0;
	        distance(edg[i].first);
	        distance(edg[i].second);
	        r = 0;
	        for(int j = 1; j <= n; j++){
	            if(d[j] > (k-1)/2) r++;
	        }
	        mini = min(mini, r);
	    }
	}
	cout << mini;
}