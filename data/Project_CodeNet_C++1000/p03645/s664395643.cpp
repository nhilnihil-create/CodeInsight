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
    vector<bool> A(N, false), B(N, false);
    A[0] = true;
    B[N - 1] = true;

    rep(i, M){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int big = max(a, b);
        int small = min(a, b);
        if(big == N - 1) B[small] = true;
        if(small == 0) A[big] = true;
    }

    bool flag = false;

    rep(i, N){
        if( A[i] && B[i] ){
            flag = true;
            break;
        } 
    }

    if(flag) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}