#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	ll w, h, p, q;
	cin >> w >> h;
	
	priority_queue<P> que;
	rep(i, 0, w){cin >> p; que.push(P(-p, 0));}
	rep(j, 0, h){cin >> q; que.push(P(-q, 1));}
	
	ll ans = 0;
	while(!que.empty()){
		ll c = -que.top().first;
		ll f = que.top().second;
		que.pop();
		if(f == 0){
			ans += c*(h+1);
			w--;
		}
		else{
			ans += c*(w+1);
			h--;
		}
	}
	print(ans)
	return 0;
}