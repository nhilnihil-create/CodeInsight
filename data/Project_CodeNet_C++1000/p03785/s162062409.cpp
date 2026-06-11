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
#include <assert.h>
#include <unordered_set>
#include <random>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)



















int main(){
    ll n, c, k;
    cin >> n >> c >> k;
    vector<ll> t(n);
    REP(i, n){
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    ll ans = 0, cnt = 0, time = 0;
    REP(i, n){
        if(cnt == c || time < t[i]){
            ans++;
            time = t[i] + k;
            cnt = 1;
        }
        else{
            cnt++;
        }
    }
    cout << ans << endl;
}