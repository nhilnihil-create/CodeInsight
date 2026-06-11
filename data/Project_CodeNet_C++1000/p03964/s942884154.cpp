#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
const ll INF = 1000000007;

// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// using Bint = mp::cpp_int;
// using Real = mp::number<mp::cpp_dec_float<1024>>;


int main(){
    int N;
    cin >> N;
    vector<int> T(N), A(N);
    rep(i, N) cin >> T[i] >> A[i];
    ll t_ans = 1, a_ans = 1;
    rep(i, N){
        ll x = (t_ans + T[i] - 1)/ T[i];
        ll y = (a_ans + A[i] - 1) / A[i];
        ll tmp = max(x, y);
        t_ans = tmp * T[i];
        a_ans = tmp * A[i];
        // cout << t_ans << ' ' << a_ans << endl;
    }
    cout << t_ans + a_ans << endl;
}