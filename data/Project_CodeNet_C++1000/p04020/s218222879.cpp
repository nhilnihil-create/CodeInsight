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
    int n; cin >> n;
    vector<long long> a(n), b(n);
    long long ans = 0, ans2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    if (n == 1) {
        cout << a[0] / 2 << endl;
        return;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] % 2 == a[i - 1] % 2) {
            ans += (a[i] + a[i - 1]) / 2;
            a[i] = 0;
        } else {
            if (a[i] != 0) {
                ans += (a[i] + a[i - 1]) / 2;
                a[i] = 1;
            }
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (b[i] % 2 == b[i + 1] % 2) {
            ans2 += (b[i] + b[i + 1]) / 2;
            b[i] = 0;
        } else {
            if (b[i] != 0) {
                ans2 += (b[i] + b[i + 1]) / 2;
                b[i] = 1;
            }
        }
    }
    cout << max(ans, ans2) << endl;
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