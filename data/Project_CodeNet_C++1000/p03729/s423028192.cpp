#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
const int INF = 2147483647;//int max
const int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    string a,b,c;
    cin >> a >> b >> c;
    if(a[a.size()-1] == b[0] && b[b.size()-1] == c[0]){
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
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