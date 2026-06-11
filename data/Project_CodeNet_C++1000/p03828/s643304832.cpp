#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> P;
int mod = 1e9+7;

vector<P> prime_factorize(int N){
	vector<P> ans;
	for(int a = 2; a*a <= N; a++){
		if(N%a == 0){
			int ex = 0;
			while(N%a == 0){
				ex++;
				N /= a;
			}
			ans.push_back(P(a, ex));
		}
	}
	if(N != 1) ans.push_back(P(N, 1));
	return ans;
}

signed main(){
	int N; cin >> N;
	int mod = 1e9 + 7;
	vector<int> exp(N + 1, 0);
	for(int n = 2; n <= N; n++){
		const auto &ans = prime_factorize(n);
		for(auto p : ans) exp[p.first] += p.second; 
	}
	int ans = 1;
	for(int i = 2; i <= N; i++){
		ans *= (exp[i] + 1);
		ans %= mod;
	}
	cout << ans << endl;
}