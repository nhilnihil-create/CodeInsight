#include <bits/stdc++.h>

using namespace std;

using i64 = long;

const i64 MOD = 1e9 + 7;
const i64 INF = 1e18 + 7;


signed main(){
    i64 n, a, b;
    cin >> n >> a >> b;
    vector<i64> v(n);
    for(auto& x : v)
        cin >> x;

    auto f = [&](i64 val){
        i64 cnt = 0;
        for(auto& x : v){
            i64 res = max(0L, x - b * val);
            cnt += (res + a - b - 1) / (a - b);
        }
        return cnt <= val;
    };

    i64 ok = MOD, ng = 0;
    while(abs(ok - ng) > 1){
        i64 mid = (ok + ng) >> 1;
        (f(mid) ? ok : ng) = mid;
    }
    cout << ok << endl;
}
