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
    map<int, int> A;
    rep(i, N){
        int a;
        cin >> a;
        if(A.count(a)) A[a]++;
        else A[a] = 1;
    }

    ll ans1 = 0, ans2 = 0;
    for(auto i : A){
        if(i.second / 2 == 0) continue;
        else if(i.second / 2 == 1){
            ans2 = ans1;
            ans1 = i.first;
        }
        else if(i.second / 2 >= 2){
            ans1 = i.first;
            ans2 = i.first;
        }
    }

    cout << ans1 * ans2 << endl;

}