#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    int n;
    cin >> n;
    vector<ll> a(n*3);
    for(int i = 0; i < n*3; ++i) cin >> a[i];

    vector<ll> l(n*2+1,0);
    priority_queue<ll, vector<ll>, greater<ll>> que1;
    for(int i = 0; i < n; ++i) {
        l[i+1] = l[i] + a[i];
        que1.push(a[i]);
    }
    for(int i = n; i < n*2; ++i) {
        ll mi = que1.top();
        if(a[i] > mi) {
            l[i+1] = l[i] - mi + a[i];
            que1.pop();
            que1.push(a[i]);
        }
        else l[i+1] = l[i];
    }

    vector<ll> r(n*2+1,0);
    priority_queue<ll> que2;
    for(int i = 0; i < n; ++i) {
        r[i+1] = r[i] + a[n*3-1 - i];
        que2.push(a[n*3-1 - i]);
    }
    for(int i = n; i < n*2; ++i) {
        ll ma = que2.top();
        if(a[n*3-1 - i] < ma) {
            r[i+1] = r[i] - ma + a[n*3-1 - i];
            que2.pop();
            que2.push(a[n*3-1 - i]);
        } 
        else r[i+1] = r[i];
    }

    ll res = -(1LL<<60);
    for(int i = n; i <= n*2; ++i) {
        res = max(res, l[i] - r[n*3-i]);
    }
    cout << res << endl;
    return 0;
}