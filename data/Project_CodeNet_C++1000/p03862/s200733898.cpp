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
    int N, X;
    cin >> N >> X;
    vector<int> A(N+1, 0);
    for(int i = 1; i <= N; i++) cin >> A[i];
    
    ll ans = 0;
    rep(i, N){
        int a = A[i] + A[i + 1];
        if(a > X){
            ans += a - X;
            A[i + 1] -= a - X;
        }
    }
    
    cout << ans << endl;
}