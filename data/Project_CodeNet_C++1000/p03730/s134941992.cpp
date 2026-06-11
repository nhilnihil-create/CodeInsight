#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;

    for(ll i=a; i<=a*b; i+=a){
        if (i % b == c){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}
