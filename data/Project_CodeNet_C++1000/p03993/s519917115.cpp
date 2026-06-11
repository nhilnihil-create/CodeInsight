#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    int n;
    std::cin >> n;
    std::vector<int> a(n,0);
    rep(i,n){
        std::cin >> a[i];
        a[i]--;
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        if(i==a[a[i]]) ans++;
    }
    std::cout << ans/2 << "\n";
    return 0;
}
