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





int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> x(n);
    vector<ll> cnt(m);
    REP(i, n){
        cin >> x[i];
        cnt[x[i] % m]++;
    }
    ll ans = 0;
    ans += cnt[0] / 2;
    cnt[0] %= 2;
    for(ll i = 1; i < (m + 1) / 2; i++){
        ll tmp = min(cnt[i], cnt[m - i]);
        ans += tmp;
        cnt[i] -= tmp;
        cnt[m - i] -= tmp;
    }
    if(m % 2 == 0){
        ans += cnt[m / 2] / 2;
        cnt[m / 2] %= 2;
    }
    sort(x.begin(), x.end());
    REP(i, n - 1){
        if(x[i] == x[i + 1] && cnt[x[i] % m] >= 2){
            cnt[x[i] % m] -= 2;
            ans++;
            i++;
        }
    }
    cout << ans << endl;
}