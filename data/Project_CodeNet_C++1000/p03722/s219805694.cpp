#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1e16;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, m;
	cin>>n>>m;
	vector<int> a(m), b(m), c(m);
	for(int i = 0; i < m; i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	vector<ll> dist(n + 1, inf);
	dist[1] = 0;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < m; j++){
			if(dist[a[j]] - c[j] < dist[b[j]]){
				dist[b[j]] = dist[a[j]] - c[j];
			}
		}
	}
	ll ans = dist[n];
	for(int j = 0; j < m; j++){
		if(dist[a[j]] - c[j] < dist[b[j]]){
			dist[b[j]] = dist[a[j]] - c[j];
		}
	}
	if(ans != dist[n]){
		cout<<"inf\n";
	}else{
		cout<<-ans<<'\n';
	}

	return 0;
}