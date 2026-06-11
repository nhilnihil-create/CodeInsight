#include<iostream>
#include<vector>
#include<string>
#include<map>

using ll = long long;

int main(){
    ll n, k;
    std::cin >> n >> k;
    std::map<ll, ll> mp;
    for(int i = 0; i < n; i++){
        ll a, b;
        std::cin >> a >> b;
        mp[a] += b;
    }

    ll length = 0;
    for(auto m : mp){
        length += m.second;
        // std::cout << m.first << " " << m.second << std::endl;
        if(length >= k){
            std::cout << m.first << std::endl;
            return 0;
        }
    }
    return 0;
}
