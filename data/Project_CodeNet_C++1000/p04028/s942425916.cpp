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
#define mx 5005

long long dep[mx][mx], n, N;

long long dp(int panjang, int sisa){
	if(sisa == 0){
		if(panjang == n)
			return 1;
		return 0;
	}
	long long &ret = dep[panjang][sisa];
	if(ret != -1)
		return ret;
	ret = 0;
	//naruh nol
	if(panjang == 0)
		ret = (ret + dp(panjang, sisa - 1)) % MOD;
	else ret = (ret + dp(panjang - 1, sisa - 1) * 2 % MOD) % MOD;
	//naruh selain nol bebas
	ret = (ret + dp(panjang + 1, sisa - 1)) % MOD;
	return ret;
}

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

int main(){
	string ss;
	cin >> N >> ss;
	n = sz(ss);
	reset(dep, -1);
	// long long dua = 1;
	// for(int i = 1; i <= n; i++)
		// dua = dua * 2 % MOD;
	// debug(dp(0, N));
	long long jaw = dp(0, N);
	cout << jaw << '\n';
}