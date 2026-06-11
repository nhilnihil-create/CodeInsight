#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7; 

vector<int> total[5005];

int solve(int k, int l) {
	if(k == 0) {
		if(l == 0) return 1;
		return 0;
	}
	if(total[k][l] != -1) return total[k][l]; 
	
	int curr = (solve(k-1, ((l > 0) ? (l-1) : l))+((2*solve(k-1, l+1)) % MOD)) % MOD;
	total[k][l] = curr;
	return curr;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, len;
	string s;
	
	cin >> n >> s;
	len = s.length();
	for(int i = 0; i <= n; i++) total[i].assign(len+n+1, -1);
	
	cout << solve(n, len);
} 