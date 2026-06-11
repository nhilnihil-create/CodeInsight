#include<iostream>
#include<vector>
#include<string>

using ll = long long;

int main(){
    ll s, c;
    std::cin >> s >> c;
    // s型を使って可能な限り作る
    if(s * 2 > c){
        // 作れない
        std::cout << c / 2 << std::endl;
    }else{
        ll cnt = 0;
        cnt += s;
        c -= s * 2;
        cnt += c / 4;
        std::cout << cnt << std::endl;
    }
    return 0;
}
