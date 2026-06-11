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
    string S;
    cin >> S;
    reverse(all(S));
    vector<string> T = {"dream", "dreamer", "erase", "eraser"};
    rep(i, 4){
        reverse(all(T[i]));
    }

    int c = 0;
    bool ans = true;

    while(c < S.size()){
        bool flag = false;
        rep(i, 4){
            if(S.substr(c, T[i].size()) == T[i]){
                flag = true;
                c += T[i].size();
                break;
            }
        }
        if(flag) continue;
        else{
            ans = false;
            break;
        }
    }

    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;

}