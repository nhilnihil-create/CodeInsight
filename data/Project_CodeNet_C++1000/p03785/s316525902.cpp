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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	ll n,c,k;cin>>n>>c>>k;
	vector<ll> t(n);
	for(ll i = 0; i < n; i++) {
		cin>>t[i];
	}
	sort(ALL(t));
	ll index = 0;
	ll ans = 0;
	while(index < n){
		auto x = upper_bound(t.begin() + index,t.end(),t[index] + k);
		ll id_up = distance(t.begin() + index,x);
		index = index + min(c,id_up);
		ans ++;
	}
	cout << ans << endl;
	return 0;
}