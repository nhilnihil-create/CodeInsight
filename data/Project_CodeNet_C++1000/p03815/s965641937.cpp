#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    ll x;
    cin >> x;
    ll d11 = x/11;
    ll m11 = x%11;
    ll ad = 0;
    if(m11==0) ad=0;
    else if(m11<=6) ad=1;
    else ad=2;

    cout << 2*d11 + ad << endl;

}
