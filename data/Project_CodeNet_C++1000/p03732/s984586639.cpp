#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
using table = vector<vector<int> >;
table create(int n, int m){
	return vector<vector<int>>(n, vector<int>(m, 0));
}
int main(){
	int n, w; cin >> n >> w;
	vector<int> wi(n), vi(n);
	for(int i = 0; i < n; i++) cin >> wi[i] >> vi[i];
	table f = create(n + 1, 4 * n), nf;
	for(int i = 0; i < n; i++){
		nf = f;
		int up = wi[i] - wi[0];
		for(int j = 0; j < n; j++){
			for(int k = 0; k + up < 4 * n; k++){
				int nwe = k + up;
				nf[j + 1][nwe] = max(nf[j + 1][nwe], f[j][k] + vi[i]);
			}
		}	
		f = nf;
	}
	int ans = 0;
	for(int j = 0; j <= n; j++){
		for(int k = 0; k < 4 * n; k++){
			if(1ll * wi[0] * j + k <= w){
				ans = max(ans, f[j][k]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}

