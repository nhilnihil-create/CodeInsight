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

#define REP(i, n) for(ll i = 0; i < n; i++)




int main() {
    ll n, k;
    cin >> n >> k;
    
    vector<ll> a(n);
    ll sum = 0;
    REP(i, n){
        cin >> a[i];
        sum += a[i];
    }
    
    if(sum < k){
        cout << n << endl;
        return 0;
    }
    
    sort(a.begin(), a.end(), greater<ll>());
    
    ll le = 0, ri = n, ce = (le + ri) / 2;
    while(ri - le > 1){
        bitset<5005> dp;
        dp[0] = true;
        REP(i, n){
            if(i == ce)continue;
            
            dp |= (dp << min(a[i], k));
        }
        
        bool need = false;
        for(ll i = max(0LL, k - a[ce]); i < k; i++){
            if(dp[i]){
                need = true;
                break;
            }
        }
        if(need){
            le = ce;
        }
        else{
            ri = ce;
        }
        ce = (le + ri) / 2;
    }
    
    cout << n - ce - 1 << endl;
}
