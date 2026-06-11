#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())
#define MOD 1000000007 
#define mx 200003

long long fak[mx], inv[mx];

long long POW(long long a, int b){
	long long ret = 1;
	while(b > 0){
		if(b & 1)
			ret = ret * a % MOD;
		b >>= 1;
		a = a * a % MOD;
	}
	return ret;
}

long long C(int n, int k){
	if(k > n)
		return 0;
	return fak[n] * inv[k] % MOD * inv[n - k] % MOD;
}

long long hitung(int atas, int bawah){
	return C(atas + bawah, atas);
}

int main(){
	fak[0] = 1;
	for(int i = 1; i <= 200000; i++)
		fak[i] = fak[i - 1] * i % MOD;
	inv[200000] = POW(fak[200000], MOD - 2);
	for(int i = 200000 - 1; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % MOD;
	int n, m, r, c;
	cin >> n >> m >> r >> c;
	long long ans = hitung(n - 1, m - 1);
	for(int i = n - r + 1; i <= n; i++){
		int x = i, y = c;
		long long satu = hitung(x - 1, y - 1);
		long long dua = hitung(n - x, m - y - 1);
		long long tot = satu * dua % MOD;
		ans = ans - tot;
		ans %= MOD;
		if(ans < 0)
			ans += MOD;
	}
	cout << ans << endl;

}