#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n,x;
    std::cin >> n>>x;
    if(x == 1 || x == 2*n-1){
        std::cout << "No" << std::endl;
        return 0;
    }
    std::cout << "Yes" << std::endl;
    if(x == n){
        for (int i = 1; i <= 2*n-1; i++) {
            std::cout << i << std::endl;
        }
        return 0;
    }else if(x<n){
        for (int i = x+1; i <= n; i++) {
            std::cout << i << std::endl;
        }
        for (int i = 1; i <= x; i++) {
            std::cout << i << std::endl;
        }
        for (int i = n+1; i <= 2*n-1; i++) {
            std::cout << i << std::endl;
        }
    }else{
        for (int i = 1; i <= n-1; i++) {
            std::cout << i << std::endl;
        }
        for (int i = x; i <= 2*n-1; i++) {
            std::cout << i << std::endl;
        }
        for (int i = n; i <= x-1; i++) {
            std::cout << i << std::endl;
        }
    }
}
 