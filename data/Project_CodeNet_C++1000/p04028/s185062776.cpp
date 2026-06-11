#include<vector>
#include<iostream>
#include<string>

using ll = long long;
const long long mod = 1000000007;
int main(){
    int n,m;
    std::string s;
    std::cin >> n >> s;
    m = s.size();
    std::vector<ll> dp(n+1,0);
    dp.at(0)++;
    for(int i=0; i<n; i++){
        std::vector<ll> nxt(n+1,0);
        for(int j=0; j<n; j++){
            nxt.at(j+1) += dp.at(j);
            nxt.at(j+1) %= mod;
            nxt.at(std::max(j-1,0)) += j==0?dp.at(j):dp.at(j)*2%mod;
            nxt.at(std::max(j-1,0)) %= mod;
        }
        dp = nxt;
    }
    std::cout << dp.at(m) << std::endl;
}