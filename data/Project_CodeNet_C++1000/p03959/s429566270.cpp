#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
int main() {
    const ll MOD = 1e9+7;
    ll n;
    std::cin >> n;
    vector<ll> t(n);
    vector<ll> a(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> t[i];
    }
    ll last_max_index = -1;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if(i>0){
            if(a[i] < a[i-1] && last_max_index == -1){
                last_max_index = i-1;
            }
        }
    }
    if(a[0] != t[n-1]){
        std::cout << 0 << std::endl;
        return 0;
    }
    
    
    if( last_max_index == -1){
        last_max_index = n-1;
    }
    
    ll now = -1;
    ll result = 1;
    
    for (int i = 0; i < last_max_index; i++) {
        // 固定
        if( t[i] > a[i] ){
            std::cout << 0 << std::endl;
            return 0;
        }
        if(t[i] == now){
            result *= now;
            result %= MOD;
        }else{
            now = t[i];
        }
    }
    now = -1;
    
    for (int i = n-1; i >= last_max_index; i--) {
        if( t[i] < a[i] ){
            std::cout << 0 << std::endl;
            return 0;
        }
        if(a[i] == now){
            result *= now;
            result %= MOD;
        }else{
            now = a[i];
        }
    }
    
    std::cout << result << std::endl;
}
