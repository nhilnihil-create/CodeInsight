#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define yes "Yes"
#define no  "No"

int main(){
    int n,m,k;
    std::cin >> n >> m >> k;

    rep(i,n+1) rep(j,m+1){
        if(i*j+(n-i)*(m-j)==k){
            std::cout << yes << "\n";
            return 0;
        }
    }

    std::cout << no << "\n";
    return 0;
}