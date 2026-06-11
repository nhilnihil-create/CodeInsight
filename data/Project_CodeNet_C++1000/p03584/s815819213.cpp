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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    REP(i, n){
        cin >> a[i] >> b[i];
    }
    
    ll ans = 0;
    REP(i, n){
        if((k | a[i]) == k){
            ans += b[i];
        }
    }
    
    for(ll i = 30; i >= 0; i--){
        if(!(k & (1 << i))) continue;
        
        ll k2 = k ^ (1 << i), t = 0;
        for(ll j = 0; j < i; j++){
            t <<= 1;
            t |= 1;
        }
        k2 |= t;
        
        // cout << k2 << endl;
        
        ll sum = 0;
        REP(j, n){
            if((k2 | a[j]) == k2){
                sum += b[j];
            }
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}
