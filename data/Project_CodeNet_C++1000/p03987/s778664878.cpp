#include<bits/stdc++.h>
using namespace std;

int main(void) {
    long n;
    cin >> n;
    vector<pair<long,long>> a(n);
    for(long i=0; i<n; i++) {
        long x;
        cin >> x;
        a[i] = {x, i};
    }
    sort(a.begin(), a.end());

    set<long> s, rs;
    s.insert(n);
    s.insert(-1);
    rs.insert(-n);
    rs.insert(+1);

    long r = 0;
    for(long i=0; i<n; i++) {
        long x, idx;
        tie(x, idx) = a[i];
        long ub = *s.lower_bound(idx);
        long lb = -(*rs.lower_bound(-idx));

        s.insert(idx);
        rs.insert(-idx);

        r += x * (ub - idx) * (idx - lb);
    }
    cout << r << endl;
}
