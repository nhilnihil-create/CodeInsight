#include<iostream>
#include<vector>
#include<string>
#include<set>

using ll = long long;
const ll MOD = 1000000007;

// ref : https://note.com/kltl/n/nb476be9d4bd6

ll pow(ll n){
    if(n == 0) return 1;
    if(n == 1) return 2;
    if(n % 2 == 0){
        ll tmp = pow(n / 2);
        return (tmp * tmp) % MOD;
    }else{
        ll tmp = pow((n - 1) / 2);
        return (2 * ((tmp * tmp) % MOD)) % MOD;
    }
}

int main(){
    ll n;
    std::cin >> n;
    std::vector<ll> a(n);
    std::vector<ll> num(n, 0);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        num[a[i]]++;
    }

    // 正しく並ぶことができるかどうか確かめる
    bool ok = true;
    for(int i = (n + 1) % 2; i < n; i += 2){
        if(i == 0){
            if(num[i] != 1){
                ok = false;
                break;
            }
        }else{
            if(num[i] != 2){
                ok = false;
                break;
            }
        }
    }
    if(!ok){
        std::cout << 0 << std::endl;
        return 0;
    }

    // 答えは2^(N / 2)
    std::cout << pow(n / 2) << std::endl;

    return 0;
}
