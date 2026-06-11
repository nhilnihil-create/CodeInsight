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

ll n, m, a, b, l, r;
string s;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n >> m;
	
	bool used[n+1];
	memset(used, 0, sizeof(used));

	vector<ll> edge[n+1];
	deque<ll> ans;
	rep(i, 1, m){
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
		if(i == 1){
			ans.push_back(a);
			ans.push_back(b);
			used[a] = true;
			used[b] = true;
		}
	}
	
	bool loop = true;
	while(loop){
		ll at = ans.front();
		for(ll i = 0; i < edge[at].size(); i++){
			ll nx = edge[at][i];
			if(!used[nx]){
				ans.push_front(nx);
				used[nx] = true;
				break;
			}
			if(i == edge[at].size()-1){
				loop = false;
			}
		}
	}
	
	loop = true;
	while(loop){
		ll at = ans.back();
		for(ll i = 0; i < edge[at].size(); i++){
			ll nx = edge[at][i];
			if(!used[nx]){
				ans.push_back(nx);
				used[nx] = true;
				break;
			}
			if(i == edge[at].size()-1){
				loop = false;
			}
		}
	}
	
	print(ans.size())
	for(auto it = ans.begin(); it != ans.end(); it++){
		cout << *it << " ";
	}
	return 0;
}