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





vector<ll> a;
vector<vector<ll>> g;
vector<bool> used;

ll dfs(ll p){
    if(used[p]) return 0;
    used[p] = true;
    if(g[p].size() == 1) return a[p];
    
    ll sum = 0, mx = -1;
    for(auto &x : g[p]){
        ll tmp = dfs(x);
        sum += tmp;
        mx = max(mx, tmp);
    }
    
    ll l = max(mx, sum / 2);
    if(l > a[p] || sum < a[p]){
        cout << "NO" << endl;
        exit(0);
    }
    
    ll t = 2 * a[p] - sum;
    if(t < 0){
        cout << "NO" << endl;
        exit(0);
    }
    
    return t;
}

int main() {
    ll n;
    cin >> n;
    a.resize(n);
    g.resize(n);
    used.resize(n);
    REP(i, n){
        cin >> a[i];
    }
    REP(i, n - 1){
        ll a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    if(n == 2){
        if(a[0] == a[1]){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        return 0;
    }
    
    REP(i, n){
        if(g[i].size() > 1){
            if(dfs(i) == 0){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
            return 0;
        }
    }
}
