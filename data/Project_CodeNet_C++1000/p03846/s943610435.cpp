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
    vector<int> A(N, 0);
    rep(i, N){
        int a;
        cin >> a;
        A[a]++;
    }

    if(N % 2 ==0){
        bool flag = true;
        for(int i = 1; i < N; i += 2){
            if(A[i] != 2){
                flag = false;
                break;
            }
        }
        if(flag){
            ll ans = 1;
            rep(i, N / 2){
                ans = ans * 2 % INF;
            }
            cout << ans << endl;
        }
        else cout << 0 << endl;
    }
    else{
        bool flag = true;
        if(A[0] != 1) flag = false;

        for(int i = 2; i < N; i += 2){
            if(A[i] != 2){
                flag = false;
                break;
            }
        }

        if(flag){
            ll ans = 1;
            rep(i, N / 2){
                ans = ans * 2 % INF;
            }
            cout << ans << endl;
        }
        else cout << 0 << endl;
    }
}