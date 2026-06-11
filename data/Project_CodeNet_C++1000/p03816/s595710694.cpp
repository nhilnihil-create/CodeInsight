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

#pragma endregion Macros

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<int> c(100001);
    rep(i,N) {
        c[A[i]]++;
    }

    rep(i,100001){
        if(c[i] >= 3){
            if(c[i]%2==0){
                c[i] = 2;
            }else{
                c[i] = 1;
            }
        }
    }

    vector<int> d(3);
    rep(i,100001){
        d[c[i]]++;
    }

    int ans = 0;
    ans += d[1];
    ans += d[2];
    if (d[2] % 2 == 1) ans--;

    cout << ans << endl;

}
