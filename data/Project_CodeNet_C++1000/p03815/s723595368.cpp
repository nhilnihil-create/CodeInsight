#include<iostream>
#include<vector>
#include<string>

using ll = long long;

int main(){
    ll x;
    std::cin >> x;
    if(x <= 6){
        std::cout << 1 << std::endl;
    }else{
        // 1回目で6,2回目で5
        ll cnt = 0;
        ll tmp = x / 11;
        x -= tmp * 11;
        cnt += tmp * 2;
        if(x > 0){
            x -= 6;
            cnt++;
        }
        if(x > 0){
            x -= 5;
            cnt++;
        }
        std::cout << cnt << std::endl;
    }
    return 0;
}
