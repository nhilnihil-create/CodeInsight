#include <bits/stdc++.h>

using namespace std;
using ll =long long;
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line
const ll mod = 1e9+7;

int main()
{
	int n;
	cin >> n;
	ll ans = 1;
	map<int,int> fact;
	for(int N = 1; N <= n; N ++){
		ll num = N;
		for(int i = 2; i * i <= N; i++){
			while(num%i==0){
				fact[i] ++;
				num /= i;
			}
		}
		if(num != 1) fact[num] ++;
	}
	for(auto x:fact){
		ans *= x.second+1;
		ans %= mod;
	}
	cout << ans << endl;
}
