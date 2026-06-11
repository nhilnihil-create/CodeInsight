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
    ll K;
    cin >> N >> K;
    map<int, ll> A;
    rep(i, N){
        int a, b;
        cin >> a >> b;
        if(A.count(a)) A[a] += b;
        else A[a] = b;
    }

    ll ans_i = K; 
    for(auto i : A){
        if(ans_i <= i.second){
            cout << i.first << endl;
            break;
        }
        ans_i -= i.second;
    }
}