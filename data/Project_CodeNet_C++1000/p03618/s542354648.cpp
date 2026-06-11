#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()


int main(){
    string a;
    cin >> a;
    vector<ll> count(27, 0);
    ll ans = 1;
    REP(i, a.size()){
        const ll d = a.at(i) - 'a';
        ans += i - count.at(d);
        count.at(d)++;
    }
    cout << ans << endl;
    return 0;
}
