#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
const int INF = 2147483647;//int max
const int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    string s;
    cin >> s;
    if(s.substr(0,4) == "YAKI")cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
/*
やっほい！
　　　　　　　やほほい！
　　　　+　　 　*
　　　 ∧∧　　. ∧∞∧　*
*　ヽ(=´ω｀)人(´ω｀*)ﾉ
　.～（ O x.） （ 　 O)～　+
。*　 　∪　　　　∪
*/