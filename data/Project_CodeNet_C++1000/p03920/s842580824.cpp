#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n;
    std::cin >> n;
    vector<ll> sum(n+1);
    
    for (int i = 0; i < n; i++) {
        sum[i+1] = sum[i]+i+1;
    }
    
    ll index = distance(sum.begin(),lower_bound(sum.begin(),sum.end(),n));
    
    for (int i = 1; i <= index; i++) {
        if(i!=sum[index]-n){
            std::cout << i << std::endl;
        }
    }
}
 