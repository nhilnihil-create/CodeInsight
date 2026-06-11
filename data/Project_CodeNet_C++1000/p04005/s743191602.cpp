#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(long long i=0;i<int(N);++i)
using ll = long long;
// const int INF = 2147483647;
const ll MOD = 1e9+7;
const ll INF = 1000000000000000000LL;
 
 
 int main() {
	 ll a,b,c;
	 cin >> a >> b >> c;
	 if(a%2==0 || b%2==0 ||c%2==0){
		 cout << 0 << endl;
		 return 0;
	 }
	 ll ans = INF;
	 ans = min(ans,a*b);
	 ans = min(ans,c*b);
	 ans = min(ans,a*c);
	 cout << ans << endl;
	 return 0;
 }
