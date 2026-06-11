#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	ll n;cin>>n;
	vector<ll> a(n);
	ll ans = 0;
	for(ll i = 0; i < n; i++) {
		cin>>a[i];
	}
	for(int i = 1; i < n - 1; i++) {
		if (a[i] != 0 && a[i] % 2 == 0 && a[i - 1] % 2 == 1&& a[i + 1] % 2 == 1){
			a[i]-= 2;
			a[i - 1] ++;
			a[i + 1] ++;
		}
		if (a[i] != 0 && a[i - 1] % 2 == 1){
			a[i]--;
			a[i - 1]++;
		}
	}
	if (n > 2 && a[n - 1] != 0 && a[n - 2] % 2 == 1){
			a[n - 1]--;
			a[n- 2]++;
		}
	for(ll i = 0; i < n; i++) {
		ans += a[i] / 2;
	}
	cout << ans << endl;
	return 0;
}