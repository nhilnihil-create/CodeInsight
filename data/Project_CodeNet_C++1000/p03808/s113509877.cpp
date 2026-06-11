#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
using ll = long long;
using pll = pair<ll, ll>;
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define VREP(s, ite) for (auto ite = s.begin(); ite != s.end(); ++ite)
#define FI first
#define SE second
//#define endl "\n"
#define ciosup  \
    cin.tie(0); \
    ios::sync_with_stdio(false);
#define eb emplace_back
#define vint vector<int>
constexpr ll INF = 1e9 + 7;
constexpr ll MOD = 1e9 + 7;

int main()
{
    ciosup;
    int n;
    cin >> n;
    vector<ll> a(n), sa(n);
    ll tot = 0;
    REP(i, n) {
        cin >> a[i];
        tot += a[i];
    }
    REP(i,n-1){
        sa[i] = a[i + 1] - a[i];
    }
    sa[n - 1] = a[0] - a[n - 1];
    ll wari = n;
    wari *= n + 1;
    wari /= 2;
    if (tot % wari == 0)
    {
        ll kai = tot / wari;
        bool flag = true;
        ll kait = 0;
        REP(i, n)
        {
            if ((kai - sa[i]) % n == 0 && (kai-sa[i])/n >= 0){
                kait += (kai - sa[i]) / n;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag && (kait == kai)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }
}