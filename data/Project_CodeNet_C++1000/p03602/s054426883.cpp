#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 1e9;

void warshall(vector<vector<int> > &adj){
	int n=adj.size();
	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
			}
		}
	}
}

int main(){
	int n;
	cin >> n;
	vector<vector<int> > a(n, vector<int>(n)), tmp;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> a[i][j];
		}
	}
	tmp = a;
	warshall(tmp);
	if(tmp != a){
		cout << -1 << endl;
		return 0;
	}
	
	long long int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int shortest = inf+1;
			for(int k=0; k<n; k++){
				if(k==i || k==j) continue;
				shortest = min(shortest, a[i][k]+a[k][j]);
			}
			if(shortest < a[i][j]){
				ans = -1;
				i = n;
				break;
			}else if(shortest > a[i][j]){
				ans += a[i][j];
			}
		}
	}
	cout << ans << endl;
	return 0;
}