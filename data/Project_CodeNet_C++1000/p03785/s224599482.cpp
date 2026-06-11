#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	ll n,c,k;
	cin >> n >> c >> k;
	vector<ll> t(n);
	rep(i,n) cin >> t[i];
	sort(t.begin(),t.end());
	ll ans = 1;
	ll now = t[0] + k;
	ll count = 1;
	REP(i,n-1){
		if(t[i] > now || count >= c) {
			ans++;
			now = t[i] + k;
			count = 1;
		}else{
			count++;
		}
	}
	cout << ans << endl;
	
    return 0;
}

