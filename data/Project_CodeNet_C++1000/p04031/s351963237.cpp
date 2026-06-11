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
    int N;
    cin >> N;
    vector<int> A(N);
    int sum = 0;
    rep(i, N){
        cin >> A[i];
        sum += A[i];
    }

    int mean = sum / N ;

    int ans = INF;
    for(int y = mean - 1; y <= mean + 1; y++){
        int tmp = 0;
        rep(i, N){
           tmp += (A[i] - y) * (A[i] - y);
        }
        ans = min(ans, tmp);
    }
    
    cout << ans << endl;
}