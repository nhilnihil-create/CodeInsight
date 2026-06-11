#include <bits/stdc++.h>

typedef long long   ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin >> n >> m;
    if(2*n>m) cout << m/2 << "\n";
    else{
        ll tmp=m-2*n;
        cout << n+tmp/4 << "\n";
    }
    return 0;
}