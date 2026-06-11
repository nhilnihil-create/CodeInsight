#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	vector<long long> vals(n);
	const long long inf = 1ll<<60;
	const int magic = 3;
	vector<vector<long long> > f(magic + 1, vector<long long>(n + 1, -inf));
	vector<char> sig(n + 1, '+');
	cin >> vals[0];
	for(int i = 1; i < n; i++){
		cin >> sig[i] >> vals[i];
	}
	f[0][0] = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < magic; j++){
			int csig = j%2 == 0?1:-1;
			if(sig[i] == '-'){
				f[j][i+1] = max(f[j][i+1], f[j][i] - csig * vals[i]);
				if(j) f[j-1][i+1] = max(f[j-1][i+1], f[j][i] - csig * vals[i]);
				f[j+1][i+1] = max(f[j+1][i+1], f[j][i] - csig * vals[i]);
			} else {
				f[j][i+1] = max(f[j][i+1], f[j][i] + csig * vals[i]);
				if(j) f[j-1][i+1] = max(f[j-1][i+1], f[j][i] + csig * vals[i]);
			}
		}
	}
	cout << f[0][n] << endl;
	return 0;
}
