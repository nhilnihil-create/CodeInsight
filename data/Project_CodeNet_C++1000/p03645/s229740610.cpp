#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define pb push_back
#define ld long double
#define f first
#define s second
#define in insert
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 1e18 + 5;
const int mod = 1e9 + 7;
const int  N = 2e5 + 314;
const long double pi = 3.1415926535897932384626433832795;
multiset<int>ms[N];
void solve(){
	int n, m;
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin>>x>>y;
		ms[x].in(y);
	}
	for(auto i:ms[1]){
		auto it = *ms[i].lower_bound(n);
		if(it==n){
			cout<<"POSSIBLE";
			return;
		}
	}
	cout<<"IMPOSSIBLE";
}
signed main(){
	speed;
	int t=1;
	//cin>>t;
	while(t--)solve();
}