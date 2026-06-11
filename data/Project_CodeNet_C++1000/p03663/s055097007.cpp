#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
struct FastIO {FastIO() { cin.tie(0); ios::sync_with_stdio(0); }}fastiofastio;
#ifdef DEBUG_ 
#include "../program_contest_library/memo/dump.hpp"
#else
#define dump(...)
#endif
const ll INF = 1LL<<60;

bool query(string s) {
    cout << "? " << s << endl;
    // const string ans_str = "1000000000";
    // bool cond1 = s <= ans_str;
    // bool cond2 = stoll(s) <= stoll(ans_str);
    // return cond1 == cond2;
    string str;
    cin >> str;
    return str == "Y";
}

int main(void) {
    // 桁数特定パート
    ll digit;
    {
        auto check = [&](ll mid) {
            return query('1' + string(mid-1, '0'));
        };

        ll lb = 1, ub = 11;
        while(ub-lb > 1) {
            ll mid = (lb+ub)/2;
            if(check(mid)) lb = mid;
            else ub = mid;
        }
        digit = lb;
    }

    // 答えは10のべき乗
    if(digit == 10) {
        auto check = [&](ll mid) {
            return query(string(mid, '9'));
        };

        ll lb = 0, ub = 10;
        while(ub-lb > 1) {
            ll mid = (lb+ub)/2;
            if(check(mid)) ub = mid;
            else lb = mid;
        }
        cout << "! 1" << string(ub-1, '0') << endl;
    }
    // digit桁で確定
    else {
        auto check = [&](ll mid) {
            return query(to_string(mid*10));
        };

        ll lb = pow(10, digit-1)-1, ub = pow(10, digit)-1;
        while(ub-lb>1) {
            ll mid = (lb+ub)/2;
            dump(lb, mid, ub);
            if(check(mid)) ub = mid;
            else lb = mid;
        }
        cout << "! " << ub << endl;
    }

    return 0;
}