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
void solve(){
	int n;
	cin>>n;
	vi v(n), pre(n);
	int mn = INF, s=0;
	for(int i = 0; i < n; i++)cin>>v[i];
	pre[0]=v[0];
	for(int i = 1; i < n; i++)pre[i]=v[i]+pre[i-1];
	for(int i = n-1; i >= 1; i--){
		s+=v[i];
		mn=min(mn, abs(pre[i-1]-s));
	}
	cout<<mn;
}
signed main(){
	speed;
	int t=1;
	//cin>>t;
	while(t--)solve();
}