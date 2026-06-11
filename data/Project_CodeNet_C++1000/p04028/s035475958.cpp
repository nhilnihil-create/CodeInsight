#include<bits/stdc++.h>

using namespace std;

#define For(i,a,b) for(int i = a ; i <= b ; ++ i)
#define int long long

const int N = 5002 , mod = 1e9 + 7;

int n , f[N][N];
string s;

int cal(int a ,int b){
	if(b == 0) return 1;
	int res = cal(a,b/2);
	res = (res * res) % mod;
	if(b%2) res = (res * a) % mod;
	return res;
}
signed main(){
	cin >> n >> s;
	int len = s.length();
	int sum = 1;
	For(i,1,len) sum = (sum * 2) % mod;
	f[0][0] = 1;
	For(i,1,n){
		For(j,0,n){
			if( j == 0) f[i][j] = ( f[i - 1][j] + f[i - 1][j + 1] ) % mod;
			else f[i][j] = (f[i - 1][j - 1] * 2 + f[i - 1][j + 1]) % mod;		
		}
	}
	int ans = f[n][len] * cal(sum , mod - 2) % mod;
	cout << ans;	
}	