#include <bits/stdc++.h>                        
#define pb push_back                            
#define mp make_pair                            
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)((x).size())
#define endl "\n"
#define jonathan ios_base::sync_with_stdio(0)
#define livingston cin.tie(0)                   
using namespace std;                            
                                                
void yes() {cout << "YES" << endl;}                                               
void no() {cout << "NO" << endl;}                                                        
                                                
int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};         
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1}; 

const long long INF = 8e18 + 8;
const double EPS = 1e-9;
const long long MOD = 998244353;

void solve() {
	long long n, x; cin >> n >> x;
	vector<long long> a(n), b(n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	long long ans = sum;
	for (int j = 1; j < n; j++) {
		sum = j * x;
		for (int i = 0; i < n; i++) {
			b[i] = min(a[i], a[(i - 1 + n) % n]);
			sum += b[i];
		}
		for (int i = 0; i < n; i++) {
			a[i] = b[i];
		}
		ans = min(ans, sum);
	}
	cout << ans << endl;
}

int main() {
    jonathan; 
    livingston;
    bool tests = 0;
    int t = 1;
    if (tests) cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}