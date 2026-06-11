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



using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)





















int main(){
    ll n;
    cin >> n;
    ll ans = 1;
    stack<ll> st;
    REP(i, n){
        ll x;
        cin >> x;
        st.push(x);
        if(st.top() < 2 * (st.size() - 1) + 1){
            ans *= st.size();
            ans %= MOD;
            st.pop();
        }
    }
    for(ll i = st.size(); i >= 1; i--){
        ans *= i;
        ans %= MOD;
    }
    cout << ans << endl;
}