#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;

int main() {
	// 毎日N人が到着
	// バス1台の定員がc人
	// 乗客は到着時刻からkだけ待ってくれる
	ll n,c,k;cin >> n >> c >> k;
	vector<ll> t(n);
	rep(i,n) cin >> t.at(i);
	sort(t.begin(),t.end());

	ll ans = 0;
	//現在時刻
  ll now = t.at(0);
	// 待たせている時間
	ll time = 0;
	// 乗客数
	ll cnt = 0;
  rep(i,n){
		if( i == 0 ){
			time = 0;
			now = t.at(i);
			cnt = 1;
		}else{
			time += t.at(i) - now;
			now = t.at(i);
			++cnt;
			if( time > k ){
				++ans;
				time = 0;
				cnt = 1;
			}else if( cnt > c ){
				++ans;
				time = 0;
				cnt = 1;
			}
		}
	}
	cout << ans+1 << endl;

	return 0;
}