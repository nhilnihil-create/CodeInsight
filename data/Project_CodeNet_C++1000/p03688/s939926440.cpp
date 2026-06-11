typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n;
    std::cin >> n;
    vector<ll> a(n);
    ll vmax = 0;
    ll vmin = n+20;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        vmax = max(vmax,a[i]);
        vmin = min(vmin,a[i]);
    }
    
    if(vmax-vmin>1){
        std::cout << "No" << std::endl;
        return 0;
    }
    
    ll num = 0;
    for (int i = 0; i < n; i++) {
        if(a[i]==vmin)num++;
    }
    
    if(num==n){
        if(vmin*2 <= n || vmin==n-1){
            std::cout << "Yes" << std::endl;
        }else{
            std::cout << "No" << std::endl;
        }
        return 0;
    }
    
    if(vmax-num<0){
        std::cout << "No" << std::endl;
        return 0;
    }
    
    if((vmax-num) == 0 || (vmax-num)*2 > n-num){
        std::cout << "No" << std::endl;
        return 0;
    }
    std::cout << "Yes" << std::endl;
    // 全部でk種類だとして、ありうる答えはkかk-1。つまりmax-minが1いない
    
    // 問題は何匹までk-1という答えが許されるか
    
    // k-1が矛盾しないためには、そいつだけが独自の帽子を被る必要がある。
    
    // 一方で、全体ではk種類だけしかない。
    

    
}