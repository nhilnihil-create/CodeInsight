#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll n, a[100008], c[100008], del[100008];
priority_queue<ll> dep[100008];
string s;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	memset(c, 0, sizeof(c));
	cin >> n;
	rep(i, 2, n){
		cin >> a[i];
		c[a[i]]++;
	}
	
	priority_queue<ll> q;
	rep(i, 1, n){
		if(c[i] == 0){
			q.push(i);	
		}
		dep[i].push(0);
	}
	
	priority_queue<ll> one;
	memset(dep, 0, sizeof(dep));
	rep(i, 2, n){
		ll ind = q.top(); q.pop();
		ll win = a[ind];
		del[win]++;
		if(del[win] == c[win]){
			q.push(win);
		}
		ll buf = 0;
		while(!dep[ind].empty()){
			buf = max(-dep[ind].top(), buf+1);
			dep[ind].pop();
		}
		dep[win].push(-(buf+1));
	}
	
	ll ans = 0;
	while(!dep[1].empty()){
		ans = max(-dep[1].top(), ans+1);
		dep[1].pop();
	}
	print(ans)
	return 0;
}