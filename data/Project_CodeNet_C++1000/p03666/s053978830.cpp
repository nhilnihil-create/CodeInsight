#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    a = b - a; //aは距離のみを表すようになった
    n--;

    //i回上にあがる
    for(ll i = n; i >= 0; i--) {
        ll up = i * d - (n - i) * c;
        ll dw = i * c - (n - i) * d;
        if(dw <= a && a <= up) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

}