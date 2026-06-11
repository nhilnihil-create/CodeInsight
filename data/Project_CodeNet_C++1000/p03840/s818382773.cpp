#include <bits/stdc++.h>
using namespace std;

int main(){
    int64_t a, b, c, d, _;
    cin >> a >> b >> _ >> c >> d >> _ >> _;
    int64_t ans = a/2*2 + b + c/2*2 + d/2*2;
    if(a && c && d){
        a--; c--; d--;
        int64_t ans2 = a/2*2 + b + c/2*2 + d/2*2 + 3;
        ans = max(ans, ans2);
    }
    cout << ans << endl;
}