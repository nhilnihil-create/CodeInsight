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
    string s;
    cin >> s;
    ll n = s.size();
    vector<vector<ll>> next(26);
    REP(i, n){
        next[s[i] - 'a'].push_back(i);
    }
    vector<ll> dp(n + 1);
    ll cnt = 1;
    vector<bool> used(26);
    for(ll i = n - 1; i >= 0; i--){
        used[s[i] - 'a'] = true;
        bool f = true;
        REP(j, 26){
            if(!used[j]){
                f = false;
                break;
            }
        }
        if(f){
            cnt++;
            REP(j, 26){
                used[j] = false;
            }
        }
        dp[i] = cnt;
    }
    string ans;
    ll p = 0;
    REP(i, dp[0]){
        REP(j, 26){
            ll idx = lower_bound(next[j].begin(), next[j].end(), p) - next[j].begin();
            if(idx == next[j].size()){
                if(dp[0] - i - 1 == 0){
                    ans += (char)('a' + j);
                    break;
                }
                continue;
            }
            ll t = next[j][idx];
            if(dp[t + 1] == dp[0] - i - 1){
                ans += (char)('a' + j);
                p = t + 1;
                break;
            }
        }
    }
    cout << ans << endl;
}
