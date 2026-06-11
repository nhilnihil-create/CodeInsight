#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;

ll n, m, a;
string s;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n >> m;
	vector<vector<ll>> A;
	
	rep(i, 0, n){
		vector<ll> tmp;
		A.push_back(tmp);
		rep(j, 0, m){
			cin >> a;
			A[i].push_back(a-1);
		}
	}
	
	ll ans = n;
	set<ll> use;
	rep(j, 0, m){
		ll cnt[m];
		memset(cnt, 0, sizeof(cnt));
		
		rep(i, 0, n){
			while(use.find(A[i][0]) != use.end()){
				A[i].erase(A[i].begin());
			}
			cnt[A[i][0]]++;
		}
		
		ll at = -1;
		ll mx = 0;
		rep(i, 0, n){
			if(cnt[A[i][0]] > mx){
				at = A[i][0];
				mx = cnt[at];
			}
		}
		
		ans = min(mx, ans);
		use.insert(at);
	}
	
	print(ans)
	return 0;
}