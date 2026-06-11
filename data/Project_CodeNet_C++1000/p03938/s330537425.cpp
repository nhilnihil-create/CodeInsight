#include<bits/stdc++.h>
using namespace std;

int main(void) {
    long n;
    cin >> n;

    vector<long> p(n);
    for(auto &e: p) cin >> e, e--;
    vector<long> q(n);
    for(long i=0; i<n; i++)
        q[p[i]] = i;

    for(long i=0; i<n; i++)
        cout << 1l + 30000l*i << ' ';
    cout << endl;
    for(long i=0; i<n; i++)
        cout << 1l + 30000l*(n-1-i) + q[i] << ' ';
    cout << endl;
}
