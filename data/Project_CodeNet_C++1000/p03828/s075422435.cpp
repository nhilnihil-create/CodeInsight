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
    vector<ll> V(N+1);

    for(int i = 1; i <= N; i++){
        int tmp = i;
        for(int j = 2; j * j <= tmp ; j++){
            while(tmp % j == 0){
                V[j]++;
                tmp /= j;
            }
        }
        V[tmp]++;
    }

    ll ans = 1;
    for(int i = 2; i <= N; i++){
        // cout << i << ": " << V[i] << endl;
        ans = ans * (V[i] + 1) % INF;
    }

    cout << ans << endl;
}