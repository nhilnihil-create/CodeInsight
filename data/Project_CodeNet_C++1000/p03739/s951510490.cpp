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
    rep(i, N) cin >> A[i];
    
    vector<ll> ans_v(2);

    for(int start_plus = 0; start_plus <= 1; start_plus++){ // 最初が+なら0, -なら1
        ll ans = 0, sum = 0;
        for(int i = 0; i < N; i++){
            sum += A[i];
            if(i % 2 == start_plus){ //sum > 0にする
                if(sum > 0) continue;
                else{
                    ans += 1 - sum;
                    sum = 1;
                }
            } 
            else if(i % 2 != start_plus){ //sum < 0にする
                if(sum < 0) continue;
                else{
                    ans += sum + 1;
                    sum = -1;
                }
            } 
        }
        ans_v[start_plus] = ans;

    } 

    cout << min(ans_v[0], ans_v[1]) << endl;
}