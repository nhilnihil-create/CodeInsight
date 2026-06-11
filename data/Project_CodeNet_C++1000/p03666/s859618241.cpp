#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

// 7 x x 6
// 7 2 6

// a,c,c,c,c,c,d,d,d,d,b

// i個目まで増加
// c*i<= sum <= d*i
// n-2-i個で減少
// c*(n-2-i)<= rsum ≤= d*(n-2-i)

// 00000000c0000000d00000
///000c00000000d

// sum-rsum が b-aからc-d以内

int main() {
    ll n,a,b,c,d;
    std::cin >> n>>a>>b>>c>>d;
    
    if(abs(a-b) > (n-1)*d){
        std::cout << "NO" << std::endl;
        return 0;
    }
    
    if(abs(a-b) >= (n-1)*c){
        std::cout << "YES" << std::endl;
        return 0;
    }
    
    for (int i = 0; i <= n-2; i++) {
        // i個目で減少
        ll sc,sd,rc,rd;
        sc = c*i;
        sd = d*i;
        rc = c*(n-2-i);
        rd = d*(n-2-i);
        
        if( (b-d-a <= sd-rc && sc-rd <= b-c-a) || (b+c-a <= sd-rc && sc-rd <= b+d-a) ){
            std::cout << "YES" << std::endl;
            return 0;
        }
    }
    std::cout << "NO" << std::endl;
}
