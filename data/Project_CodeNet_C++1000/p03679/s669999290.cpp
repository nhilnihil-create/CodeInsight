#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF 2147483647//int max
const int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int x,a,b;
    cin >> x >> a >> b;
    if(a >= b){
        cout << "delicious\n";
    }else if (x >= b-a)
    {
        cout << "safe\n";
    }else{
        cout << "dangerous\n";
    }
    
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