#include <bits/stdc++.h>
#define int long long
#define moder 1000000007
#define inf 1000000000000000000
#define rep(i,n) for(int i=0;i<n;i++)
#define P pair<int,int>
#define all(v) v.begin(),v.end()
#define prique(T) priority_queue<T,vector<T>,greater<T>>
#define vecunique(vec) sort(vec.begin(), vec.end());decltype(vec)::iterator result = std::unique(vec.begin(), vec.end());vec.erase(result, vec.end())
using namespace std;
bool prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)return false;
	}
	return n != 1;
}
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}
int mod_pow(int x, int y, int mod) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x%mod;
		}
		x = x * x%mod;
		y >>= 1;
	}
	return res;
}
int kai(int x) {
	if (x == 0)return 1;
	return (kai(x - 1)*x) % moder;
}
int comb(int x, int y) {
	return kai(x)*mod_pow(kai(x - y), moder - 2, moder) % moder*mod_pow(kai(y), moder - 2, moder) % moder;
}
/*--------Library Zone!--------*/
int h,w,a,b,ans;
int meup,medown;
signed main() {
	cin>>h>>w>>a>>b;
	ans+=comb(h-a-1+b,b)*comb(a+w-b-2,a-1);
	meup=comb(h-a-1+b,b),medown=comb(a+w-b-2,a-1);
	ans%=moder;
	for(int i=b+2;i<=w;i++){
		meup=meup*(h-a+i-2)%moder*mod_pow((i-1),moder-2,moder)%moder;
		medown=medown*(w-i+1)%moder*mod_pow((w-i+a),moder-2,moder)%moder;
		ans+=meup*medown%moder;
		ans%=moder;
	}
	cout<<ans<<endl;
}
