#include <bits/stdc++.h>
#define cout16 cout << setprecision(16) 
#define rep(i,n) for(int i=0;i<n;i++ )
#define rep2(i,f,n) for(int i=f;i<n;i++ )
#define SORT(A) sort(A.begin(),A.end())
#define REV(A) reverse(A.begin(),A.end())
typedef long long int ll;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vll = std::vector<ll>;
using vvll = std::vector<std::vector<ll>>;
using P = std::pair<int,int>;
using vp = std::vector<P>;
using namespace std;
#define INF 1001001001
#define LL_INF 1001001001001001001
#define fi first
#define se second

int main(void) {
	int n; cin >> n;
	vll a(n); rep(i,n) cin >> a[i];
	SORT(a);
	vll s(n,0);
	s[0] = a[0];
	rep(i,n-1) s[i+1] = s[i]+a[i+1];
	int ans = 1;
	for(int i=n-2; i>=0; i--){
		ll x = s[i];
		if(a[i+1]<=x*2) ans++;
		else break;
	}
	cout << ans << endl;
}
