#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
	cout << fixed << setprecision(10);
	ll ans = 0;
	int n;
	cin >> n;
	vector<int> a(n),b(n);
	rep(i,n) cin >> a[i] >> b[i];
	for(int i = n-1; i >= 0 ; i--){
		if((a[i]+ans)%b[i] == 0) continue;
		else{
			ll nn = b[i]*((a[i]+ans)/b[i]+1);
			ans += nn - a[i]-ans ;
		}
	}
	cout << ans << endl;
	return 0;
}