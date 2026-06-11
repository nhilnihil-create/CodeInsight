#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;
int f[2][5050];
int n , l;
string s;

int main(){
	cin >> n >> s;
	l = s.size();
	f[0][0] = 1;
	for(int i = 1 ; i <= n ; ++ i){
		memset(f[i & 1] , 0 , sizeof f[i & 1]);
		int last = 1 - (i & 1);
		for(int j = 1 ; j <= i ; ++ j){
			f[i & 1][j] = (f[i & 1][j] + 2ll * f[last][j - 1]) % MOD;
			f[i & 1][j] = (f[i & 1][j] + f[last][j + 1]) % MOD;
		}
		f[i & 1][0] = (f[last][1] + f[last][0]) % MOD;
	}
	int ans = f[n & 1][l];
	for(int i = 1 ; i <= l ; ++ i)
		ans = 1ll * ans * 500000004 % MOD;
	cout << ans << endl;
	return 0;
}