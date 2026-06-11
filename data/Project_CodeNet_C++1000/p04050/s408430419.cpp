#include<bits/stdc++.h>
#define pb push_back
#define fr first
#define sc second
#define all(x) x.begin(), x.end()
#define skip continue
#define NAME "code"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
void faster(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const ll MAXN = 2e3 + 123;
const ld EPS = 1e-12;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int n, m;
vector<int> q[2], ans;

void solve(){
	cin >> n >> m;

	for(int i = 0, x; i < m; ++i){
		cin >> x;
		q[x & 1].pb(x);
		if(m == 1){
			if(x > 1){
				cout << x << '\n';
				cout << 2 << '\n';
				cout << x - 1 << ' ' << 1 << '\n';
			}
			else{
				cout << x << '\n';
				cout << 1 << '\n';
				cout << x << '\n';
			}
			return;
		}
	}

	if(q[1].size() > 2){
		cout << "Impossible";
		return;
	}

	if(!q[1].empty()){
		ans.pb(q[1].back());
		q[1].pop_back();
	}

	for(int x : q[0])
		ans.pb(x);

	if(!q[1].empty()){
		ans.pb(q[1].back());
		q[1].pop_back();
	}

	for(int x : ans){
		cout << x << ' ';
	}

	ans.front()--;
	ans.back()++;
	if(!ans.front())
		ans.erase(ans.begin());

	cout << '\n' << ans.size() << '\n';
	
	for(int x : ans){
		cout << x << ' ';
	}
}

int main(){

	faster();
 
	int T = 1;
	// cin >> T;
	
	while(T--){
		solve();
	}
 
	return 0;
}