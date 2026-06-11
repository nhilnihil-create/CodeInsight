#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef vector<ll> vl;


int main()
{
    int n;
    cin >> n;
    vl a(3*n);
    rep(i,3*n) cin >> a[i];

    vl l(2*n+1);
    priority_queue<ll, vector<ll>, greater<ll>> que;
    for(int i = 0; i < n; ++i) {
        l[i+1] = l[i] + a[i];
        que.push(a[i]);
    }
    for(int i = n; i < 2*n; ++i) {
        ll m = que.top();
        if(a[i] > m) {
            l[i+1] = l[i] - m + a[i];
            que.pop();
            que.push(a[i]);
        } else l[i+1] = l[i];
    }

    reverse(a.begin(),a.end());
    vl r(2*n+1);
    priority_queue<ll> que2;
    for(int i = 0; i < n; ++i) {
        r[i+1] = r[i] + a[i];
        que2.push(a[i]);
    }
    for(int i = n; i < 2*n; ++i) {
        ll M = que2.top();
        if(a[i] < M) {
            r[i+1] = r[i] - M + a[i];
            que2.pop();
            que2.push(a[i]);
        } else r[i+1] = r[i];
    }

    ll res = -(1LL << 60);
    for(int i = n; i <= n*2; ++i) {
        res = max(res, l[i]-r[n*3-i]);
    }
    cout << res << endl;
    return 0;
}