#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using ll = long long;

int main(){
    ll n, x;
    std::cin >> n >> x;
    ll a, b = 0;
    std::cin >> a;
    ll cnt = 0;
    for(int i = 1; i < n; i++){
        std::cin >> b;
        // aとbをチェック
        if(a + b > x){
            // bから先に食べる
            ll tmp = std::min(a + b - x, b);
            cnt += tmp;
            b = b - tmp;
            // まだダメ
            if(a + b > x){
                tmp = a + b - x;
                cnt += tmp;
                a = a - tmp;
            }
        }
        a = b;
    }

    std::cout << cnt << std::endl;
    return 0;
}
