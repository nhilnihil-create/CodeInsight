#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
const int INF = 1000000007;

// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// using Bint = mp::cpp_int;
// using Real = mp::number<mp::cpp_dec_float<1024>>;

int main(){
    ll N, M;
    cin >> N >> M;
    // ll ans = (M - 2 * N) / 4;
    // if(ans < 0) cout << M / 2 << endl;
    // else{
    //     ll a1 = min(N + ans, M / 2 - ans);
    //     ans++;
    //     ll a2 = min(N + ans, M / 2 - ans);
    //     cout << max(a1, a2) << endl;
    // }
    if(N > M / 2) cout << M / 2 << endl;
    else cout << N + (M - 2 * N) / 4 << endl;
}