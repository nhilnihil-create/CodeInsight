#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
using ll = long long;
using pll = pair<ll, ll>;
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
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
    ll k;
    cin >> k;
    vector<ll> a(50);
    if (k == 0){
        cout << 2 << endl;
        cout << 1 << " " << 1 << endl;
    }else{
        ll ad = k / 50;
        ll amari = k % 50;
        REP(i,50){
            a[i] = 49 + ad;
        }
        REP(i,amari){
            a[i] += 50;
            REP(j,50){
                if (j != i){
                    --a[j];
                }
            }
        }
        cout << 50 << endl;
        REP(i, 49) { cout << a[i] << " "; }
        cout << a[49] << endl;
    }
}