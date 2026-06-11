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
    int N, M;
    cin >> N >> M;
    if(abs(N - M) > 1) cout << 0 << endl;
    else{
        ll ans = 1;
        for(int i = 1; i <= N; i++){
            ans = (ans * i) % INF;
        }
        for(int i = 1; i <= M; i++){
            ans = (ans * i) % INF;
        }
        if(N == M) ans = (ans * 2) % INF;
        cout << ans << endl;
    }
}