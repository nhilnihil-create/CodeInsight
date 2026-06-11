#include<bits/stdc++.h>
#include <numeric>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }

ll gcd(ll m, ll n) {
    ll tmp;
    while (m % n != 0) {
        tmp = n;
        n = m % n;
        m = tmp;
    }
    return n;
}

ll lcm(ll m, ll n) {
    return max(m, n)/gcd(m,n) * min(m,n);
}


int main() {
    ll n; cin >> n;

    ll tmp = n % 11;
    if(tmp == 0) {
        cout << (n/11)*2 << endl;
        return 0;
    }
    ll odd = (n/11)%2;
    if(odd == 1) {
        if(tmp <= 5) {
            cout << ((n/11)*2)+1 << endl;
        } else {
            cout << ((n/11)*2)+2 << endl;
        }
    } else {
        if(tmp <= 6) {
            cout << ((n/11)*2)+1 << endl;
        } else {
            cout << ((n/11)*2)+2 << endl;
        }
    }


    return 0;
}
