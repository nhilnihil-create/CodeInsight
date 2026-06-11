typedef  long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n,m;
    std::cin >> n>>m;
    
    vector<ll>    c(100010,0);
    vector<ll> oddc(100010,0);
    
    for (int i = 0; i < n; i++) {
        ll t;
        std::cin >> t;
        c[t]++;
    }
    ll mc = 0;
    
    for (int i = 0; i <= 100000; i++) {
        if(i%m==0){
            mc += c[i];
            continue;
        }
        if(c[i]%2==1){
            oddc[i%m]++;
            c[i]--;
        }
        
    }
    ll ans = 0;
    for (int i = 1; i < m; i++) {
        ll dif = min(oddc[i],oddc[m-i]);
        ans += dif;
        oddc[i]-=dif;
        oddc[m-i]-=dif;
    }
    // std::cout << ans << std::endl;
    for (int i = 0; i <= 100000; i++) {
        if(i%m==0)continue;
        ll dif = min(c[i],oddc[m-i%m]);
        ans += dif;
        c[i]-=dif;
        oddc[m-i%m]-=dif;
        ans += c[i]/2;
    }
    
    ans += mc/2;
    
    
    std::cout << ans << std::endl;
    
    
}
