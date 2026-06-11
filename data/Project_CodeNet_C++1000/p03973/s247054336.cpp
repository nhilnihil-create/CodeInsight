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


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(int i = 0; i < n; i++)




int main() {
    ll n;
    cin >> n;
    
    vector<ll> a(n);
    REP(i, n){
        cin >> a[i];
    }
    
    ll k = 1, ans = a[0] - 1;
    for(int i = 1; i < n; i++){
        if(k + 1 < a[i]){
            ans += (a[i] - 1) / (k + 1);
        }
        else{
            k = max(k, a[i]);
        }
        // cout << ans << ' ' << k << endl;
    }
    
    cout << ans << endl;
}
