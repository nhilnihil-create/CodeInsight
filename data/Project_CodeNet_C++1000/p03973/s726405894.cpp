#include <bits/stdc++.h>
 
#define int long long
 
#define pii pair<int, int>
 
#define x1 x1228
#define y1 y1228
 
#define left left228
#define right right228

#define tm tm228
 
#define pb push_back
#define eb emplace_back
 
#define mp make_pair                                                                
                                                                                                                                        
#define ff first                                                                  
#define ss second   
 
#define all(x) x.begin(), x.end()
#define debug(x) cout << #x << ": " << x << endl; 
#define TIME (ld)clock()/CLOCKS_PER_SEC
 
using namespace std;
typedef long long ll; 
typedef long double ld; 
                                                                                                   
const int maxn = 3e5 + 7, mod = 1e9 + 7, MAXN = 1e6 + 7;
const double eps = 1e-9;
const ll INF = 1e18, inf = 1e15;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int n; 
int a[maxn]; 

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; 
    }  
    int lst = 1; 
    int ans = 0; 
    for (int i = 0; i < n; ++i) { 
        if (a[i] <= lst) {  
            lst = max(lst, a[i] + 1); 
            continue; 
        } else {
            if (a[i] % lst == 0) ans += a[i] / lst - 1; 
            else ans += a[i] /= lst; 
            lst = max(lst, 2ll); 
        }                      
    }
    cout << ans; 
}                                
   
signed main() {
#ifdef LOCAL
    freopen("TASK.in", "r", stdin);
    freopen("TASK.out", "w", stdout);
#else 
    
#endif // LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20); 
    cout << fixed; 
    int t = 1; 
    for (int i = 0; i < t; ++i) {              
        solve();
    }
    return 0;
} 