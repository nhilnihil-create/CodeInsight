#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using ll = long long;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main(){
    ll n;
    std::cin >> n;
    std::vector<ll> T(n);
    for(int i = 0; i < n; i++){
        std::cin >> T[i];
    }

    // 例外処理
    if(n == 1){
        std::cout << T[0] << std::endl;
        return 0;
    }

    std::sort(T.begin(), T.end());    

    ll g = gcd(T[0], T[1]);
    ll lcm = (T[0] / g) * (T[1] / g) * g;
    for(int i = 2; i < n; i++){
        g = gcd(lcm, T[i]);
        lcm = (lcm / g) * (T[i] / g) * g;
    }

    std::cout << lcm << std::endl;
    return 0;
}
