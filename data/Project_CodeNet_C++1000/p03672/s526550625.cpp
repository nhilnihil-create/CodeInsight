#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#pragma region Macros
#define FOR(i, m, n) for (ll i = (ll)(m); i < (ll)(n); i++)
#define rep(i, n) FOR(i, 0, n)

template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

template <class T> string join(const T &v, const string delim = ",")
{
    if (v.empty())
        return "";

    ostringstream res;
    res << v[0];
    for (int i = 1; i < v.size(); i++)
    {
        res << delim << v[i];
    }
    return res.str();
}

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << ":" << #x << " = " << (x) << endl;
#else
#define dbg
#endif

#pragma endregion Macros

bool f(const string &s){
    for (int i = 0; i < s.size() / 2;i++){
        if (s[i] != s[i + s.size() / 2]) return false;
    }
    return true;
}

int main()
{
    string S;
    cin >> S;

    ll ans = 100100100;
    for (int i = 2; i < S.size(); i += 2) {
        if(f(S.substr(0, S.size()-i))){
            ans = S.size() - i;
            break;
        }
    }

    cout << ans << endl;
}
