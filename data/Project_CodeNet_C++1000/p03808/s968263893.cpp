#include<bits/stdc++.h>
#define pb push_back
#define fr first
#define sc second
#define all(x) x.begin(), x.end()
#define skip continue
#define NAME "code"
#define tabs(a, b) ((a<b) ? (b-a) : (a-b))
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
void faster(){
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
const ull INF = 1e9;
const ll MOD = 1e9 + 7;
const ll MAXN = 3e5 + 123;
const ld EPS = 1e-12;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
 
ll n, sum, a[MAXN];
 
void solve(){
	cin >> n;
 
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		sum += a[i];
	}
 
	if(sum % (n * (n + 1) / 2) != 0){
		cout << "NO\n";
		return;
	}
 
	ll k = sum / (n * (n + 1) / 2);
 
	for(int i = 0; i < n; ++i){
		if((k - (a[(i + 1) % n] - a[i])) % n != 0 || (k - (a[(i + 1) % n] - a[i])) < 0){
			cout << "NO\n";
			return;
		}
	}
 
	cout << "YES\n";
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