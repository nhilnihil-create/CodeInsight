#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof a);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define per(i,a,b) for(int i = a; i >= b; i--)
#define __ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef double db;
const db EPS = 1e-9;
using namespace std;

void dbg() {cout << "\n";}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
#define logs(x...) {cout << #x << " -> "; dbg(x);}

int T;

int solve(int n,int x){
	int ans = n;
	int h1 = x, h2 = n-x;
	while(1){
		if(h1 == h2) {ans += h1; break;}
		if(h1 < h2){
			ans += 2*h1;
			h2 -= h1;
		}
		else{
			ans += 2*h2;
			h1 -= h2;
		}
	}
	T = h1;
	return ans;
}

ll gcd(ll x,ll y){
	return y == 0 ? x:gcd(y,x%y);
}

ll n,x;

int main()
{
	scanf("%lld%lld",&n,&x);
	ll ans = (n-1ll)*3ll;
	ll thp = gcd(n,x);
	ans -= (thp-1ll)*3ll;
	printf("%lld\n",ans);
	// rep(n,2,100){
	// 	printf("\n");
	// 	rep(x,1,n-1){
	// 		printf("n:%d, x:%d, gcd:%d, ans:%d\n",n,x,gcd(n,x),solve(n,x));
	// 	}
	// }
	return 0;
}