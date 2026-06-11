typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    ll n,t;
    ll a[100010];
    std::cin >> n>>t;
    ll ma = 0;
    ll mi = 1e10;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        ma = max(a[i],ma);
        mi = min(a[i],mi);
    }
    
    ll max_v[100010];
    ll min_v[100010];
    
    max_v[n-1] = a[n-1];
    min_v[0] = a[0];
    
    for (int i = n-2; i >= 0; i--) {
        max_v[i] = max(max_v[i+1],a[i]);
    }
    for (int i = 1; i < n; i++) {
        min_v[i] = min(min_v[i-1],a[i]);
    }
    ll p1[100010];
    ll p2[100010];
    
    for (int i = 0; i < n-1; i++) {
        p1[i] = max_v[i+1]-a[i];
    }
    for (int i = 1; i < n; i++) {
        p2[i] = a[i] - min_v[i-1];
    }
    sort(p1,p1+n-1);
    sort(p2,p2+n-1);
    ll d1 = distance(p1,lower_bound(p1,p1+n-1,p1[n-2]));
    ll d2 = distance(p2,lower_bound(p2,p2+n-1,p2[n-2]));
    // std::cout << n-1-d1<<" "<<n-1-d2 << std::endl;
    std::cout << max(n-1-d1,n-1-d2) << std::endl;
}
