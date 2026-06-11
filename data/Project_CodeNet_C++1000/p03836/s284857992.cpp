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
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int X = tx - sx, Y = ty - sy;
    
    rep(i, Y) cout << 'U';
    rep(i, X) cout << 'R';
    rep(i, Y) cout << 'D';
    rep(i, X) cout << 'L';
    
    cout << 'L';
    rep(i, Y+1) cout << 'U';
    rep(i, X+1) cout << 'R';
    cout << 'D';
    cout << 'R';
    rep(i, Y+1) cout << 'D';
    rep(i, X+1) cout << 'L';
    cout << 'U';

}