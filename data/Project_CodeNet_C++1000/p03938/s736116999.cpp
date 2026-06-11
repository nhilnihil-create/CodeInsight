#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n;
    std::cin >> n;
    vector<ll> p(n);
    for (int i = 0; i < n; i++) {
        ll r;
        std::cin >> r;
        r--;
        p[r] = i;
    }
    
    for (int i = 1; i <= n-1; i++) {
        std::cout << i*20010<<" ";
    }
    std::cout <<  n*20010 << std::endl;
    for (int i = 1; i <= n-1; i++) {
        std::cout << (n+1-i)*20010+p[i-1]<<" ";
    }
    std::cout << 20010+p[n-1] << std::endl;
}
 
