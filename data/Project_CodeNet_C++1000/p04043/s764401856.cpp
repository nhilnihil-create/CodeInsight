#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a,b,c;
    cin >> a >> b >> c;
    ll d = max(max(a,b),c);
    ll e = min(min(a,b),c);
    if (d == 7 && e == 5 && a + b + c == 17) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

}

