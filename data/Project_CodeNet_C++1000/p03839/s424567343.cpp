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
const ll MAXN = 3e5 + 123;
const ld EPS = 1e-12;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

ll n, k, ans, a[MAXN], pref[MAXN], suff[MAXN], pref_sum[MAXN];

void solve(){
	cin >> n >> k;

	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		pref[i] = pref[i - 1] + (a[i] > 0) * a[i];
		pref_sum[i] = pref_sum[i - 1] + a[i];
	}

	for(int i = n; i >= 1; --i){
		suff[i] = suff[i + 1] + (a[i] > 0) * a[i];
	}

	for(int i = 1; i + k - 1 <= n; ++i){
		ans = max(max(pref_sum[i + k - 1] - pref_sum[i - 1], 0ll) + pref[i - 1] + suff[i + k], ans);
	}

	cout << ans;
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