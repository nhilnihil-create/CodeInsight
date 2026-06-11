#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n+1);
    long long sum=0;
    for ( int i=0; i<n; i++ ) {
        cin >> a[i];
        sum+=a[i];
    }
    long long m=(long long)n*(n+1)/2;
    if ( sum%m ){
        cout << "NO" << '\n';
        return 0;
    }
    m = sum/m;
    a[n]=a[0];
    // (k-d)/n = x
    sum = 0;
    for ( int i=0; i<n; i++ ) {
        // cout << a[i+1] << ' ' << a[i] << '\n';
        long long d=(a[i+1] - a[i]);
        if ( m<d || (m-d)%n ){
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
    return 0;
}
