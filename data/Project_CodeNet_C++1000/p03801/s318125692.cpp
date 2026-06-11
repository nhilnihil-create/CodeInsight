typedef long long ll;
typedef long double ld;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n;
    std::cin >> n;
    vector<ll> a(n),b(n);
    ll s = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        b[i] = a[i];
        s += a[i];
    }
    sort(b.begin(),b.end());
    vector<ll> sum(n+1,0);
    for (int i = 0; i < n; i++) {
        sum[i+1] = sum[i]+b[i];
    }
    ll rem = s;
    ll now = 0;
    for (int i = 0; i < n; i++) {
        if(now>=a[i]){
            std::cout << 0 << std::endl;
            continue;
        }
        now = a[i];
        auto idx = distance(b.begin(),upper_bound(b.begin(),b.end(),now));
        std::cout << rem-(sum[n]-sum[idx]-now*(n-idx)) << std::endl;
        rem -= rem-(sum[n]-sum[idx]-now*(n-idx));
    }
}
