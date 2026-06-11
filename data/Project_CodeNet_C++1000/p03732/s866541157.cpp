#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	int n, w, w1;
	cin >> n >> w;
	vector<ll> val[4];
	ll vv;
	cin >> w1 >> vv;
	val[0].push_back(vv);	
	for(int i = 0 ; i < n - 1; ++i){
		ll wR, v;
		cin >> wR >> v;
		val[wR-w1].push_back(v);
	}
	for(int i = 0; i < 4; ++i){
		sort(val[i].begin(), val[i].end(), greater<ll>());
		val[i].insert(val[i].begin(), 0);
		for(int j = 1; j < (int)val[i].size(); ++j) val[i][j] += val[i][j-1];
	}
	ll sol = 0;
	for(ll i = 0; i < (int)val[0].size(); ++i){
		for(ll j = 0; j < (int)val[1].size(); ++j){
			for(ll k = 0; k < (int)val[2].size(); ++k){
				for(ll p = 0; p < (int)val[3].size(); ++p){
					if(w < (w1*(i+j+k+p)+j+2*k+3*p)) break;
					sol = max(sol, val[0][i]+val[1][j]+val[2][k]+val[3][p]);
				}
			}
		}
	}
	cout << sol << "\n";
	return 0;
}

