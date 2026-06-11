#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<long> a(3*n);
    for(auto &x: a) cin >> x;

    vector<long> l(n+1);
    {
        long sum = 0;
        priority_queue<long> q;
        for(int i=0; i<n; i++) sum += a[i], q.push(-a[i]);

        l[0] = sum;
        for(int i=0; i<n; i++) {
            long aa = a[i+n];
            long t = -q.top();
            if(aa > t) {
                sum += aa - t;
                q.pop();
                q.push(-a[i+n]);
            }
            l[i+1] = sum;
        }
    }

    vector<long> r(n+1);
    {
        long sum = 0;
        priority_queue<long> q;
        for(int i=0; i<n; i++) sum += a[3*n-1-i], q.push(a[3*n-1-i]);

        r[n] = sum;
        for(int i=0; i<n; i++) {
            long aa = a[3*n-1-(i+n)];
            long t = q.top();
            if(aa < t) {
                sum += aa - t;
                q.pop();
                q.push(a[3*n-1-(i+n)]);
            }
            r[n-1-i] = sum;
        }
    }

    /* for(auto &x: l) cout << x << ' '; */
    /* cout << endl; */

    /* for(auto &x: r) cout << x << ' '; */
    /* cout << endl; */

    long res = -1e18;
    for(int i=0; i<=n; i++)
        res = max(l[i] - r[i], res);

    cout << res << endl;
}
