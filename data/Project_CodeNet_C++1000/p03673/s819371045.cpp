#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b;
    rep(i, n){
        cin >> a[i];
        if ((i % 2 == 0 && n % 2 == 0) || (i % 2 == 1 && n % 2 == 1) ){
            b.push_back(a[i]);
        }else{
            b.insert(b.begin(), a[i]);
        }
    }
    rep(i, n-1){
        cout << b[i] << " ";
    }
    cout << b[n-1] << endl;


    return 0;
}
