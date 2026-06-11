#include<bits/stdc++.h>
using namespace std;

int main(void) {
    long n, k;
    cin >> n >> k;

    map<long, long> m;
    for(long i=0; i<n; i++) {
        long a, b;
        cin >> a >> b;
        m[a] += b;
    }

    long r = 0;
    for(long i=0; i<=30; i++) {
        long mk = (k>>i<<i)-1;
        if(mk < 0) continue;
        long rr = 0;
        for(auto &t: m) {
            long a, b;
            tie(a, b) = t;
            if((a|mk) == mk)
                rr += b;
        }
        r = max(r, rr);
    }
    {
        long mk = k;
        long rr = 0;
        for(auto &t: m) {
            long a, b;
            tie(a, b) = t;
            if((a|mk) == mk)
                rr += b;
        }
        r = max(r, rr);
    }
    cout << r << endl;
}
