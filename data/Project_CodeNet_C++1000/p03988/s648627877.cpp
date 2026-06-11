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
    ll n;
    cin >> n;
    bool one = false;
    ll cnt[105] = {};
    ll mx = -1, mn = INF;
    REP(i, n){
        ll a;
        cin >> a;
        cnt[a]++;
        mx = max(mx, a);
        mn = min(mn, a);
    }
    for(ll i = mx; i >= (mx + 1) / 2; i--){
        if(i == (mx + 1) / 2 && mx % 2 == 0){
            if(cnt[i] < 1){
                cout << "Impossible" << endl;
                return 0;
            }
            cnt[i]--;
            continue;
        }
        if(cnt[i] < 2){
            cout << "Impossible" << endl;
            return 0;
        }
        cnt[i] -= 2;
    }
    for(ll i = 1; i <= (mx + 1) / 2; i++){
        if(cnt[i]){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
}
