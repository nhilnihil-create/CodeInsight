#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define int long long
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
signed main(){
	cout << fixed << setprecision(10);
	ll n,k;
	cin >> n >> k;
	vector<pair<int,ll>> v;
	rep(i,n){
		int a,b;
		cin >> a >> b;
		v.push_back({a,b});
	}
	sort(v.begin(),v.end());
	ll cnt = 0;
	rep(i,n){
		if(cnt + v[i].second >= k){
			cout << v[i].first << endl;
			return 0;
		}
		cnt += v[i].second;
	}
	return 0;
}