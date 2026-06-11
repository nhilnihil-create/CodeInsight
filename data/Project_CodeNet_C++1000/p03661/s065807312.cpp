typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main() {
    ll n;
    ll a[200010];
    ll sum = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        sum += a[i];
    }
    ll origin = sum;
    ll result = 1e10;
    for (int i = 0; i < n-1; i++) {
        sum-=a[i];
        result = min(result, abs(sum-(origin-sum)));
    }
    std::cout << result << std::endl;
    
}
