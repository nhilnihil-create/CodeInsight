#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
using ll = long long;

int main(){
    ll n; std::cin>>n;
    std::vector<ll> a;
    for(int i=0; i<n; ++i){
        ll b; std::cin>>b; a.push_back(b);
    }

    std::vector<ll> flag(9, 0);
    for(int i=0; i<n; ++i){
        if(1<=a[i]&&a[i]<400){
            ++flag[0];
        }else if( 400<=a[i]&&a[i]<800){
            ++flag[1];
        }else if( 800<=a[i]&&a[i]<1200){
            ++flag[2];
        }else if(1200<=a[i]&&a[i]<1600){
            ++flag[3];
        }else if(1600<=a[i]&&a[i]<2000){
            ++flag[4];
        }else if(2000<=a[i]&&a[i]<2400){
            ++flag[5];
        }else if(2400<=a[i]&&a[i]<2800){
            ++flag[6];
        }else if(2800<=a[i]&&a[i]<3200){
            ++flag[7];
        }else{
            ++flag[8];
        }
    }

    ll ans = 0;
    for(int i=0; i<8; ++i){
        if(flag[i]>0) ++ans;
    }
    std::cout << std::max(ans, 1LL) << " " << ans + flag[8];
    return 0;
}
