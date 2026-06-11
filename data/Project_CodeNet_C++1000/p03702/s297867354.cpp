#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main() {
    ll n,a,b;
    std::cin >> n>>a>>b;
    vector<ll> h(n);
    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
    }

    ll r = 1e10;
    ll l = 0;
    // r ok, l だめ
    while(r-l>1){
        ll mid = (r+l)/2;
        ll tmp = 0;
        for (int i = 0; i < n; i++) {
            if( (h[i]-mid*b) >0){
                tmp += (h[i]-mid*b+(a-b-1))/(a-b);
            }
        }
        if(mid<tmp){
            l = mid;
        }else{
            r = mid;
        }
    }
    std::cout << r << std::endl;
}
