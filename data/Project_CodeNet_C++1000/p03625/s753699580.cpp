#include<iostream>
#include<vector>
#include<string>
#include<map>

using ll = long long;

int main(){
    ll n;
    std::cin >> n;
    std::map<ll, ll, std::greater<ll>> mp;
    for(int i = 0; i < n; i++){
        ll a;
        std::cin >> a;
        mp[a]++;
    }

    std::vector<ll> ans;
    for(auto m : mp){
        if(m.second >= 4 && ans.size() == 0){
            std::cout << m.first * m.first << std::endl;
            return 0;
        }else if(m.second >= 2 && ans.size() == 1){
            std::cout << ans[0] * m.first << std::endl;
            return 0;
        }else if(m.second >= 2){
            ans.push_back(m.first);
        }
    }

    std::cout << 0 << std::endl;

    return 0;
}
