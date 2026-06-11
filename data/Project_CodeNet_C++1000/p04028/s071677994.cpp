#include <bits/stdc++.h>
using namespace std;
int main(){
	int m; cin >> m;
	string s; cin >> s;
	const int mod = 1'000'000'007;
	int len = s.size(), n = 5001;
	vector<int> f(2 * n, 0), nf;
	f[len] = 1;
	for(int i = 0; i < m; i++){
		nf.assign(2 * n, 0);
		for(int j = 0; j < 2 * n; j++){
			if(f[j]){
				nf[j + 1] += f[j];
				if(nf[j + 1] >= mod) nf[j + 1] -= mod;
				nf[j + 1] += f[j];
				if(nf[j + 1] >= mod) nf[j + 1] -= mod;
				int nm = max(0, j - 1);
				nf[nm] += f[j];
				if(nf[nm] >= mod) nf[nm] -= mod;
			}
		}
		f = nf;
	}
	cout << f[0] << endl;
	return 0;
}
