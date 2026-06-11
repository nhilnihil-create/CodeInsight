#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define Yes(condition) if(condition){ cout << "Yes" << '\n'; }else{ cout << "No" << '\n'; }
#define YES(condition) if(condition){ cout << "YES" << '\n'; }else{ cout << "NO" << '\n'; }
#define yes(condition) if(condition){ cout << "yes" << '\n'; }else{ cout << "no" << '\n'; }




int main() {
    ll w, h;
    cin >> w >> h;
    vector<pair<ll, ll>> a(w + h);
    REP(i, w + h){
        ll t;
        cin >> t;
        a[i] = {t, (i < w)? 0 : 1};
    }
    sort(a.begin(), a.end());
    ll x = w + 1, y = h + 1;
    ll ans = 0;
    REP(i, w + h){
        if(a[i].second == 0){
            ans += a[i].first * y;
            x--;
        }
        else{
            ans += a[i].first * x;
            y--;
        }
    }
    cout << ans << endl;
}