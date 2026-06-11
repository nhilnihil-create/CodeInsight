#include <bits/stdc++.h>

#define pb push_back
#define ins insert 
#define ers erase 
#define all(x) x.begin(), x.end()
#define F first 
#define S second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef string str;
typedef long double ld;

const ll N = 2e5 + 10;
const ll INF = 1e18;
const ll MOD = 1e9 + 10;

ll Cnt, n, a[N], Max, t;
map<ll, ll> Cnt_Max;
map<ll, vector<ll>> koj;
map<ll, ll> joons;

int main(){
	cin >> n >> t;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		koj[a[i]].pb(i);
	}
	ll ans = 0;
	for (int i = n; i > 0; i--){
		ans = max(ans, Max - a[i]);
		Max = max(Max, a[i]);
	}
	Max = 0;
	ll cnMax = 0;
	for (int i = n; i > 0; i--){
		if (Max - a[i] == ans){
			joons[a[i]] ++;
			Cnt_Max[a[i]] = cnMax;
		}
		if (Max == a[i]){
			cnMax ++;
		}else if(Max < a[i]){
			cnMax = 1;
			Max = a[i];
		} 
	}
	for (auto u:joons){
		Cnt += min(Cnt_Max[u.F], u.S);
	}
	cout << Cnt;
	
	
	
	return 0;
}