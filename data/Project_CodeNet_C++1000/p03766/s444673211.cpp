#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000200, mod = 1'000'000'007;
int mul(long long a, long long b){
	return a * b % mod;
}
int f[maxn];
int main(){
	int n; cin >> n;
	f[1] = n;
	f[2] = mul(n, n);
	int sum = f[1] + f[2]; if(sum >= mod) sum -= mod;
	for(int i = 3; i <= n; i++){
		f[i] += sum;
		f[i] += mod - f[i - 2];
		if(f[i] >= mod) f[i] -= mod;
		f[i] += mul(n - 1, n - 1);
		if(f[i] >= mod) f[i] -= mod;
		f[i] += n - i + 2;
		if(f[i] >= mod) f[i] -= mod;
		sum += f[i];
		if(sum >= mod) sum -= mod;
	}
	cout << f[n] << endl;
	return 0;
}
