#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    long q,h,s,d,n;
    cin >>q>>h>>s>>d>>n;
    q *= 4;
    h *= 2;
    long minimum = min(q,h);
    minimum = min(minimum,s);
    long ans = 0;
    if(n >= 2){
        if(2*minimum > d){
            ans = n/2 * d;
            n = n%2;
        }
    }
    ans += n*minimum;
    cout << ans <<endl;
}