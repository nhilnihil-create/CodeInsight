#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n,k;
    std::cin >> n>>k;
    vector<ll> a(n);
    
    vector<ll> psum(n+1);
    vector<ll> sum( n+1);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        sum[i+1] = sum[i]+a[i];
        psum[i+1] = psum[i];
        if(a[i]>0){
            psum[i+1] += a[i];
        }
    }
    
    ll result = -1e18;

    for (int i = 0; i < n-k+1; i++) {
        result = max(result,psum[n]-( psum[i+k]-psum[i] )+max( (ll)0, sum[i+k]-sum[i] ) );
    }
    std::cout << result << std::endl;
    // どれくらい柔軟な範囲のとり方ができるか。
    
    // 全部はいける kで撮ったあまりはいける
    
    // 2*k以下なら真ん中の自由度はなさそう。
    
    // どこかのk意外の場所は任意の色にできる？
    // その他のプラス分の合計+kの色（）
}
