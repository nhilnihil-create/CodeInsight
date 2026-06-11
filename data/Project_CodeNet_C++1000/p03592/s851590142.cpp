#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main(){
	ll n, m, k; cin >> n >> m >> k;
	for(ll i = 0; i <= n; ++i){
		for(ll j = 0; j <= m; ++j){
			if(i * m + j * n - 2 * i * j == k){
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
    return 0;
}
