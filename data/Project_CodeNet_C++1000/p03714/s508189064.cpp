#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(un ique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> a(3 * n);
    rep(i, 3 * n) cin >> a[i];
    ll ans = LONG_MIN;
    priority_queue<int> greater_pq;
    priority_queue<int, vector<int>, greater<int>> less_pq;
    vector<ll> fdp(n + 1), ldp(n + 1);
    ll fsum = 0, lsum = 0;
    
    rep(i, n) fsum += a[i];
    fdp[0] = fsum;
    rep(i, n) less_pq.push(a[i]);
    
    reps(i, 1, n + 1) {
        int v = less_pq.top();
        
        if (a[n + i - 1] > v) {
            fsum = fsum + a[n + i - 1] - v;
            less_pq.pop();
            less_pq.push(a[n + i - 1]);
        }
        
        fdp[i] = fsum;
    }
    
    reps(i, 2 * n, 3 * n) lsum += a[i];
    ldp[n] = lsum;
    reps(i, 2 * n, 3 * n) greater_pq.push(a[i]);
    
    rrep(i, n) {
        int v = greater_pq.top();
        
        if (a[n + i] < v) {
            lsum = lsum - (v - a[n + i]);
            greater_pq.pop();
            greater_pq.push(a[n + i]);
        }
        
        ldp[i] = lsum;
    }
    
    rep(i, n + 1) {
        ans = max(ans, fdp[i] - ldp[i]);
    }
    
    cout << ans << endl;
    return 0;
}