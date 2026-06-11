typedef long long ll;
typedef long double ld;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n;
    std::cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(),a.end());
    if(a[0]==a[n-1]){
        if(a[0]==n-1){
            std::cout << "Yes" << std::endl;
            return 0;
        }
        if(a[0]*2<=n){
            std::cout << "Yes" << std::endl;
            return 0;
        }
        std::cout << "No" << std::endl;
        return 0;
    }
    
    if(a[0]==a[n-1]-1){
        ll x = a[n-1]*n-sum;
        if(a[n-1]-x<=0){
            std::cout << "No" << std::endl;
            return 0;
        }
        if((a[n-1]-x)*2<=n-x){
            std::cout << "Yes" << std::endl;
        }else{
            std::cout << "No" << std::endl;
        }
    }else{
        std::cout << "No" << std::endl;
        return 0;
    }
}