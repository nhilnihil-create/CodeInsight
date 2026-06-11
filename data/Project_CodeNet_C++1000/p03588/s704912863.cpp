#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = 2*1e18;
const int inf = 1e9+7;

using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> a(n),b(n);
	int right = -1;
	int left  = -1;
	int mx = 0;
	int mn = inf;
	rep(i,n){
		cin >> a[i] >> b[i];
		if(mn>b[i]){
			mn = min(mn,b[i]);
			right = a[i];
		}
		if(mx<b[i]){
			left = a[i];
			mx = b[i];
		}
	}
	ll ans = 1+(right - left);
	ans += left - 1;
	ans += mn;
	cout << ans << endl;
}