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
    vector<int> A(3);
    rep(i, N){
        int a;
        cin >> a;
        if(a % 4 == 0) A[0]++;
        else if (a % 2 == 0) A[1]++;
        else A[2]++;
    }

    if(A[1] == 0 && A[2] <= 1 + A[0]) cout << "Yes" << endl;
    else if ( A[1] != 0 && A[2] <= A[0]) cout << "Yes" << endl;
    else cout << "No" << endl;
}