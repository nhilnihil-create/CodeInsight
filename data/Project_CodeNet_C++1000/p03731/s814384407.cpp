#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
const int INF = 2147483647;//int max
const int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    ll n,t;
    cin >> n >> t;
    ll sum = 0;
    vector<ll> time(n,0);
    rep(i,n){
        cin >> time.at(i);
        if(i == 0){
            sum += t;
        }else{
            //前が途切れた
            if(t < (time.at(i) - time.at(i-1))){
                sum += t;
            }else{
                sum += t;
                sum -= t -( time.at(i) - time.at(i-1));
            }
        }
    }
    cout << sum << endl;
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