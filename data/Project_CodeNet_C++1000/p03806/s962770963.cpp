#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set> 
#include <map>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iomanip>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001; // > 10^9
const int MOD = (int)1e9 + 7;
const ll INFLL = 1001001001001001001;  // > 10^18
const ll MODLL = (ll)1e9 + 7;
const double EPS = 1e-9;

int main () {
    
    ll n,ma,mb; cin >>n>>ma>>mb;
    vector<ll> a(n); vector<ll> b(n); vector<ll> c(n);
    rep(i,n) cin >> a[i] >> b[i] >> c[i];

    ll n1 = n/2;
    vector<P> pairs1((1<<n1));

    ll ans1 = INFLL;
    for (ll s = 0; s < (1<<n1); s++) {
        ll suma = 0;
        ll sumb = 0;
        ll sumc = 0;
        for (ll i = 0; i < n1; i++) {
            if (s & (1<<i)) {
                suma += a[i];
                sumb += b[i];
                sumc += c[i];
            }
        }
        pairs1[s] = P((ma+mb)*suma - ma*(suma+sumb), sumc);
        if ((ma+mb)*suma - ma*(suma+sumb) == 0 && sumc > 0 && ans1 > sumc) {
            ans1 = sumc;
        } 
    }

    sort(pairs1.begin(), pairs1.end());

    ll ans = INFLL;
    for (ll s = 0; s < (1<<(n-n1)); s++) {
        ll suma = 0;
        ll sumb = 0;
        ll sumc = 0;
        for (ll i = 0; i < (n-n1); i++) {
            if (s & (1<<i)) {
                suma += a[n1 + i];
                sumb += b[n1 + i];
                sumc += c[n1 + i];
            }
        }
        ll m = ma*(suma+sumb) - (ma+mb)*suma;
        ll ok = (1<<n1);
        ll ng = -1;
        while (abs(ng-ok)>1) {
            ll mid = (ok+ng)/2;
            if (m <= pairs1[mid].first) {
                ok = mid;
            } else {
                ng = mid;
            } 
        }
        if (m == pairs1[ok].first) {
            if (ans > sumc + pairs1[ok].second && sumc + pairs1[ok].second > 0) {
                ans = sumc + pairs1[ok].second;
            } 
        } 
    }

    if (ans == INFLL && ans1 == INFLL) {
        cout << -1 << endl;
    } else {
        cout << min(ans, ans1) << endl;
    } 

    return 0;
}

