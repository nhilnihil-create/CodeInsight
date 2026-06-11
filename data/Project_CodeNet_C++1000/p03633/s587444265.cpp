#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL gcd(LL a, LL b) {
    return ( b==0 ) ? a : gcd(b,a%b);
}

int main() {
    int n;
    LL s=1;
    cin >> n;
    for ( int i=0; i<n; i++ ) {
        LL a;
        cin >> a;
        s=a/gcd(a,s)*s;
    }
    cout << s << '\n';
    return 0;
}
