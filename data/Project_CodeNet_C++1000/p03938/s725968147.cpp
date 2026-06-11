#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()
template<class T>
using reverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;

int main(){
    ll n;
    cin >> n;
    vector<ll> p(n);
    REP(i, n){
        cin >> p.at(i);
        p.at(i)--;
    }

    vector<ll> a(n);
    REP(i, n){
        a.at(i) = 1 + i * n;
    }
    vector<ll> b(a);
    reverse(ALL(b));

    for(ll i = 1; i < n; ++i){
        const ll pi = p.at(i);
        const ll pj = p.at(i - 1);
        ll abi = a.at(pi) + b.at(pi);
        ll abj = a.at(pj) + b.at(pj);
        if(abj >= abi){
            a.at(pi) += abj - abi + 1;
        }
    }

    REP(i, n){
        cout << a.at(i);
        if(i + 1 < n){ cout << ' '; }
    }
    cout << endl;

    REP(i, n){
        cout << b.at(i);
        if(i + 1 < n){ cout << ' '; }
    }
    cout << endl;

    return 0;
}
