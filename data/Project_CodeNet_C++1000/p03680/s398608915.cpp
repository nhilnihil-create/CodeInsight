#include<bits/stdc++.h>
using namespace std ; 
# define pb push_back
# define ll long long
# define mp make_pair 
# define endl "\n"
# define vi vector<int>
# define vc vector<char>
# define vll vector<ll> 
# define pi pair<int,int> 
const int MOD = 1e9 + 7 ; 
const ll inf = 1e18 ; 

void solve() {
	int n ; 
	cin >> n ; 
	vi a(n) ; 
	for(int i=0; i < n ; ++i)
		cin >> a[i] ; 
	vector<bool> vis(n) ; 
	int i=0 ; 
	int cnt= 0 ; 
	bool ok = false ; 
	while(true) {
		//cout << i ; 
		if(vis[i]) {
			ok = false ;
			break ; 
		}
		if(i == 1) {
			ok = true ; 
			break ; 
		}
		vis[i] = true ; 
		i = a[i]-1 ;
		cnt++;  
	}
	if(ok) {
		cout << cnt ; 
	} else {
		cout << -1 ; 
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ; 
	int t ; 
	//cin >> t ; 
	t = 1 ;
	while(t--)
		solve() ; 
	return 0; 
}
