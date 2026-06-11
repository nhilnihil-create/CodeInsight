#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> a(N);
    ll total = 0, st = 0, ans = __LONG_LONG_MAX__;
    
    rep(i, N) {
        cin >> a[i];
        total += a[i];
    }
    
    rep(i, N) {
        st += a[i];
        
        if (i < (N - 1)) {
            ans = min(ans, abs(total - 2 * st));
        }
    }
    
    cout << ans << endl;
    return 0;
}
