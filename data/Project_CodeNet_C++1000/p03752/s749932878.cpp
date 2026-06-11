#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<stack>
#include<string>
#include<cstring>
#include<time.h>
#include<iomanip>
#include<list>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<bitset>
#include <queue>
#include <map>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldouble = long double;

#define repi(i,a,b) for(ll i = (a); i < (b); i++)
#define rep(i, n) for(ll i = 0; i < (n); ++i)


int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    ll res = 1e18;
    for (uint b = 0; ((b >> (N-1)) & 1) != 1; ++b) {
        vector<int> buf = a;
        ll mx = buf[0];
        ll sum = 0;
        repi(i, 1, N) if (((b >> (i - 1)) & 1) == 1) {
            sum += max(0ll, mx + 1 - buf[i]);
            buf[i] = max(mx + 1, (ll)buf[i]);
            mx = max(mx + 1, (ll)buf[i]);
        }
        int c = 1;
        mx = buf[0];
        repi(i,1, N) {
            if (buf[i] > mx) {
                c++;
                mx = buf[i];
            }
        }
        if(c >= K) res = min(res, sum);
    }
    cout << res << endl;
    return 0;
}

