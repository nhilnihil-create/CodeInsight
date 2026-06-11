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
const ll MAXN = 2e5 + 123;
const ld PI = acos(-1);

int n, a[MAXN], ans;
map<int, int> id;

void solve(){
	cin >> n;

	for(int i = 0; i < n; ++i){
		cin >> a[i];
		id[a[i]] = i & 1;
	}

	sort(a, a + n);

	for(int i = 0; i < n; ++i)
		ans += (i & 1) != (id[a[i]] & 1);

	cout << ans / 2;
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