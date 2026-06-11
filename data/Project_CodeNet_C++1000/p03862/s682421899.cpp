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
    vector<int> A(100010);
    for(int i = 1; i <= N; i++) cin >> A[i];
    
    ll ans = 0;
    for(int i = 1; i <= N; i++){
        int a = A[i - 1] + A[i];
        int b = A[i + 1] + A[i];
        int c = min(a, b);
        if(c > X){
            if(A[i] >= c - X){
                A[i] -= c - X;
                ans += c - X;
            } else {
                ans += A[i];
                A[i] = 0;
            }
            
        }
    }
    
    for(int i = 1; i <= N; i++){
        int b = A[i + 1] + A[i];
        if(b > X){
            if(A[i] >= b - X){
                A[i] -= b - X;
                ans += b - X;
            } else {
                ans += A[i];
                A[i] = 0;
            }
        }
    }

    cout << ans << endl;
}