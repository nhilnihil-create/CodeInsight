#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7; int f[1000003] , N;

int main(){
	cin >> N; f[0] = f[1] = 1; int sum = 2 , ans = 0;
	for(int i = 2 ; i <= N - 1 ; ++i){f[i] = (sum - f[i - 2] + MOD) % MOD; sum = (sum + f[i]) % MOD;}
	ans = 1ll * f[N - 1] * N % MOD;
	for(int i = N - 2 ; ~i ; --i) ans = (ans + 1ll * f[i] * (1ll * (N - 1) * (N - 1) % MOD + min(N - 1 , i + 2))) % MOD;
	cout << ans; return 0;
}
