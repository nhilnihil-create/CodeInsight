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
    ll n;
    cin >> n;
    
    ll m = 1;
    while(m * (m + 1) / 2 < n){
        m++;
    }
    
    vector<ll> ans;
    for(ll i = m; n > 0; i--){
        if(i <= n){
            n -= i;
            ans.push_back(i);
        }
    }
    
    reverse(ans.begin(), ans.end());
    
    REP(i, ans.size()){
        cout << ans[i] << '\n';
    }
}
