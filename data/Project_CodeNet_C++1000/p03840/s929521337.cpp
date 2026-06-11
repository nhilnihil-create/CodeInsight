// #define _GLIBCXX_DEBUG // for STL debug (optional)
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;
using ll = long long int;
using int64 = long long int;
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int INF = 1LL << 29;
const ll LONGINF = 1LL << 60;
const ll MOD = 1000000007LL;
 
int main() {
    ll I_, O_, T_, J_, L_, S_, Z_;
    cin >> I_ >> O_ >> T_ >> J_ >> L_ >> S_ >> Z_;

    ll ans = 0;
    for(ll x=0; x<2; x++) {
        ll I = I_, O = O_, T = T_, J = J_, L = L_, S = S_, Z = Z_;
        if(min({I, J, L}) < x) continue;

        ll K = 0;
        
        // I, J, L 1 個ずつ
        {
            K += 6LL * x;
            I -= x, J -= x, L -= x;
        }
        
        // I を 2 個
        {
            K += 4LL * (I / 2);
            I %= 2;
        }
        
        // O を 1 個
        {
            K += 2LL * O;
            O = 0;
        }

        // J を 2 個
        {
            K += 4LL * (J / 2);
            J %= 2;
        }

        // L を 2 個
        {
            K += 4LL * (L / 2);
            L %= 2;
        }

        // I, J, L 1 個ずつ
        {
            ll mi = min({I, J, L});
            K += 6LL * mi;
            I -= mi, J -= mi, L -= mi;
        }
        chmax(ans, K / 2);
    }
    cout << ans << endl;
    return 0;
}
