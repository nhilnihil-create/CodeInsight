#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	ll h, w;
	cin >> h >> w;
	string a[h];
	ll cnt[30];
	memset(cnt, 0, sizeof(cnt));
	zep(i, 0, h){
		cin >> a[i];
		zep(j, 0, w){
			cnt[a[i][j] - 'a']++;
		}
	}
	ll cnt4 = 0;
	ll cnt2 = 0;
	ll cnt1 = 0;
	rep(i, 0, 25){
		cnt4 += cnt[i]/4;
		cnt[i] %= 4;
		cnt2 += cnt[i]/2;
		cnt[i] %= 2;
		cnt1 += cnt[i];
	}
	bool ans = true;
	if(h%2 == 0 && w%2 == 0){
		if(cnt2 > 0 || cnt1 > 0){
			ans = false;
		}
	}
	if(h%2 == 1 && w%2 == 0){
		if(cnt2 > w/2 || cnt1 > 0){
			ans = false;
		}
	}
	if(h%2 == 0 && w%2 == 1){
		if(cnt2 > h/2 || cnt1 > 0){
			ans = false;
		}
	}
	if(h%2 == 1 && w%2 == 1){
		if(cnt2+cnt1 > w/2+h/2+1 || cnt1 > 1){
			ans = false;
		}
	}
	if(ans){
		print("Yes")
	}
	else{
		print("No")
	}
	return 0;
}