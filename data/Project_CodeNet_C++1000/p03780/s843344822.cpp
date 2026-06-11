#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }
template<typename T> inline T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }





int n, k;
vector<int> a;

bool check(int x) { // 不必要
    
    if (a[x] >= k) return 0;
    
    int dp[n + 1][k + 1];
    fill_n(*dp, (n + 1) * (k + 1), 0);
    
    
    rep(j, n) {
        if (x == j) {
            rep(l, k + 1) dp[j + 1][l] = dp[j][l];
            continue;
        }
        
        rep(l, k + 1) {
            if (l == 0) {
                if (a[j] >= k - a[x] && a[j] < k) return 0;
                dp[j + 1][(a[j] > k ? k : a[j])] = 1;
            } else if (dp[j][l] == 0) continue;
            else {
                if (a[j] + l >= k - a[x] && a[j] + l < k) return 0; // 1にしてたorz
                dp[j + 1][(a[j] + l > k ? k : a[j] + l)] = 1;
            }
            
        }
    }
    
    return 1;
}

template<typename T>
void binary_search(T ok, T ng) {
    while (abs(ng - ok) > 1) {
        T mid = (ng + ok) / 2;
        // cout << mid << endl;
        (check(mid) ? ok : ng) = mid;
        // cout << ok << " " << ng << endl;
    }
    cout << ok + 1 << endl;
}






int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    
    cin >> n >> k;
    rep(i, n) { int A; cin >> A; a.eb(A); }
    sort(all(a));
    binary_search(-1, n);
    
}

