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
    ll H, W, h, w;
    cin >> H >> W >> h >> w;
    
    if(H % h == 0 && W % w == 0){
        cout << "No" << endl;
        return 0;
    }
    
    vector<vector<ll>> ans(H, vector<ll>(W));
    if(W % w != 0){
        ll minus = -(w * 2 - 1);
        ll sum = 0;
        REP(j, W){
            ans[0][j] = j % w == w - 1? minus : 2;
            sum += ans[0][j];
        }
        while(sum <= 0){
            REP(j, W){
                ll t = j % w == w - 1? -2 * (w - 1) : 2;
                ans[0][j] += t;
                sum += t;
            }
        }
        REP(i, H - 1){
            REP(j, W){
                ans[i + 1][j] = ans[i][j];
            }
        }
    }
    else{
        ll minus = -(h * 2 - 1);
        ll sum = 0;
        REP(i, H){
            ans[i][0] = i % h == h - 1? minus : 2;
            sum += ans[i][0];
        }
        while(sum <= 0){
            REP(i, H){
                ll t = i % h == h - 1? -2 * (h - 1) : 2;
                ans[i][0] += t;
                sum += t;
            }
        }
        REP(i, H){
            REP(j, W - 1){
                ans[i][j + 1] = ans[i][j];
            }
        }
    }
    
    cout << "Yes" << endl;
    REP(i, H){
        REP(j, W){
            cout << ans[i][j] << " \n"[j == W - 1];
        }
    }
}
