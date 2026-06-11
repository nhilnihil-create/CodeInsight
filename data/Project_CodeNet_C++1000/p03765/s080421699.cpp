#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()
template<class T>
using reverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;

const string YES = "YES";
const string NO = "NO";

ll calc_num_a(const vector<ll>& v, ll l, ll r){
    if(l >= r || v.size() == 0){ return 0; }
    r = min((ll)v.size(), r);
    ll ret = v.at(r - 1);
    if(l > 0){
        ret -= v.at(l - 1);
    }
    return ret;
}

bool solve(ll na, ll nb, ll ma, ll mb){
    ll n3 = (na - nb) % 3;
    if(n3 < 0){ n3 += 3; }

    ll m3 = (ma - mb) % 3;
    if(m3 < 0){ m3 += 3; }

    return n3 == m3;
}

int main(){
    string s, t;
    cin >> s >> t;
    vector<ll> cs(s.size(), 0), ct(t.size(), 0);

    REP(i, s.size()){
        cs.at(i) = s.at(i) == 'A';
        if(i > 0){ cs.at(i) += cs.at(i - 1); }
    }

    REP(i, t.size()){
        ct.at(i) = t.at(i) == 'A';
        if(i > 0){ ct.at(i) += ct.at(i - 1); }
    }

    ll q;
    cin >> q;
    REP(i, q){
        ll ai, bi, ci, di;
        cin >> ai >> bi >> ci >> di;
        const ll s_na = calc_num_a(cs, ai - 1, bi);
        const ll s_nb = bi - ai + 1 - s_na;

        const ll t_na = calc_num_a(ct, ci - 1, di);
        const ll t_nb = di - ci + 1 -t_na;
        if(solve(s_na, s_nb, t_na, t_nb)){
            cout << YES << endl;
        }else{
            cout << NO << endl;
        }
    }

    return 0;
}
