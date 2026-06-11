#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using ll = long long;
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

// おまけ
long long lcm(long long a, long long b){
    return a * (b / gcd(a, b));
}

int main(){
    ll n;
    std::cin >> n;
    ll ans = 1;
    for(int i = 0; i < n; i++){
        ll t;
        std::cin >> t;
        ans = lcm(ans, t);
    }

    std::cout << ans << std::endl;
    return 0;
}
