#include<bits/stdc++.h>
using namespace std;

int main(void) {
    long n;
    cin >> n;
    vector<long> a(n);
    for(auto &e: a) cin >> e;
    sort(a.begin(), a.end());

    long m = a[n-1];

    if(m == 1) {
        cout << (n==2 ? "Possible" : "Impossible") << endl;
        return 0;
    }
    if(m%2 == 0) {
        bool ok = true;
        for(long i=m/2 + 1; i<=m; i++)
            ok &= (upper_bound(a.begin(), a.end(), i) - lower_bound(a.begin(), a.end(), i)) >= 2;
        ok &= a[0] == m/2;
        ok &= a[1] > m/2;

        cout << (ok ? "Possible" : "Impossible") << endl;
    } else {
        bool ok = true;
        for(long i=(m+1)/2; i<=m; i++)
            ok &= (upper_bound(a.begin(), a.end(), i) - lower_bound(a.begin(), a.end(), i)) >= 2;
        ok &= a[0] == (m+1)/2;
        ok &= a[1] == (m+1)/2;
        ok &= a[2] > (m+1)/2;

        cout << (ok ? "Possible" : "Impossible") << endl;
    }
}
