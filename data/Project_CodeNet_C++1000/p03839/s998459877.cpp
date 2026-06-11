#include<bits/stdc++.h>
using namespace std;

int main(void) {
    long n, k;
    cin >> n >> k;
    vector<long> a(n);
    for(auto &e: a) cin >> e;

    vector<long> ps(n+1), ns(n+1);
    for(long i=1; i<=n; i++) {
        ps[i] = ps[i-1] + max(a[i-1], 0l);
        ns[i] = ns[i-1] + min(a[i-1], 0l);
    }

    long r = 0;
    for(long i=0; i+k<=n; i++) {
        // 0 .. [i, i+k) .. n-1
        // 1 .. i [i+1, i+k] i+k+1 .. n
        long t = (ps[n] - ps[i+k]) + (ps[i] - ps[0]);
        r = max(r, t + (ps[i+k]-ps[i]) + (ns[i+k]-ns[i]));
        r = max(r, t);
    }
    cout << r << endl;

}
