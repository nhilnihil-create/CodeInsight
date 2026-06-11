#pragma region
#pragma GCC target("avx2")
#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std; typedef long double ld; typedef long long ll;
typedef unsigned long long ull;
#define endl "\n"
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORR(x,arr) for(auto& x:arr)
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define VPII vector<PII>
#define VPLL vector<PLL>
#define FI first 
#define SE second
#define ALL(x) (x).begin(), (x).end()
constexpr int INF=1<<30; constexpr ll LINF=1LL<<60; constexpr ll mod=1e9+7; constexpr int NIL = -1;
template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
#pragma endregion
//-------------------
int n;
const int MX = 1e5 + 7;
ll a[MX];
ll b[MX];

int main(){
    cin.tie(0); ios::sync_with_stdio(false); //cout << fixed << setprecision(15);
    cin >> n;
    FOR(i,0,n-1) cin >> a[i];
    FOR(i,1,n-1) a[i] += a[i-1];
    FOR(i,0,n-1) b[i] = a[i];

    ll total = 0;
    ll cnt1 = 0;
    ll cnt2 = 0;
    // a[0] < 0
    FOR(i,0,n-1) {
        a[i] += total;
        if(i%2==0) {
            if(a[i] > 0) continue;
            else {
                cnt1 += 1LL - a[i];
                total += 1LL - a[i];
            }
        } else {
            if(a[i] < 0) continue;
            else {
                cnt1 += a[i] + 1LL;
                total -= a[i] + 1LL;
            }
        }
    }
    total = 0;
    FOR(i,0,n-1) {
        b[i] += total;
        if(i%2==1) {
            if(b[i] > 0) continue;
            else {
                cnt2 += 1LL - b[i];
                total += 1LL - b[i];
            }
        } else {
            if(b[i] < 0) continue;
            else {
                cnt2 += b[i] + 1LL;
                total -= b[i] + 1LL;
            }
        }
    }
    cout << min(cnt1, cnt2) << endl;
    return 0;
}
