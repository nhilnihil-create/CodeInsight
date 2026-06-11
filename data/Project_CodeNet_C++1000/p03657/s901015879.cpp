#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
const int INF = 2147483647;//int max
const int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int a,b;
    cin >> a >> b;
    if(a%3 == 0 || b%3 == 0 || (a+b)%3 == 0){
        cout << "Possible\n";
    }else cout << "Impossible\n";
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