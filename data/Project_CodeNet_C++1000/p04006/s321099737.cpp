#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < int(n); i++)
#define FOR(i,n,m) for(int i = int(n); i < int(m); i++)
using namespace std;
typedef long long ll;

// スライド最小値 O(N)
// return[i] = min( v[i,i+k) )
template< typename T >
vector< T > slide_min(const vector< T > &v, int k)
{
    deque< int > deq;
    vector< T > ret;
    for (int i = 0; i < v.size(); i++) {
        while (!deq.empty() && v[deq.back()] >= v[i]) {
            deq.pop_back();
        }
        deq.push_back(i);
        if (i - k + 1 >= 0) {
            ret.emplace_back(v[deq.front()]);
            if (deq.front() == i - k + 1) deq.pop_front();
        }
    }
    return ret;
}

int main() {
    const ll LLINF = 1e18;
    int n, x; cin >> n >> x;
    vector<int> v(n << 1);
    REP(i, n) {
        cin >> v[n - 1 - i];
        v[n - 1 - i + n] = v[n - 1 - i];
    }
    ll ans = 1e18;
    FOR(k,1,n+1) {
        auto sm = slide_min(v, k);
        ll sum = 0;
        REP(i, n) sum += sm[i];
        ans = min(ans, sum + (ll)x * (k-1));
    }
    cout << ans << endl;
    return 0;
}