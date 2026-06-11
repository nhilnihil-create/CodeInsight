#include<bits/stdc++.h>
using namespace std;

int main(void) {
    long n, a, b;
    cin >> n >> a >> b;

    vector<long> v(n);
    for(auto &e: v) cin >> e;

    sort(v.begin(), v.end(), greater<>());

    long t = 0;
    for(long i=0; i<a; i++)
        t += v[i];
    // t/a

    long m = v[a-1], cm = 0, cmt = 0;
    for(long i=0; i<n; i++)
        if(v[i] == m) {
            if(i<a) cmt++;
            cm++;
        }

    auto comb = [&](long a, long b) {
        long r = 1;
        for(long i=0; i<b; i++)
            r *= a-i, r /= i+1;
        return (long)r;
    };

    cout << setprecision(16) << 1.0*t/a << endl;
    if(cmt == a) {
        // sum [a<=i<=b] (cm C i)
        long r = 0;
        for(long i=a; i<=b; i++)
            r += comb(cm, i);
        cout << r << endl;
    } else {
        // cm C cmt
        cout << comb(cm, cmt) << endl;
    }
}
