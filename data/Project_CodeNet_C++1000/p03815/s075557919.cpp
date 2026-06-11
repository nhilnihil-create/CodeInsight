#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(long long x){
    ll ans = 0;
    if(x <= 6) ans = 1;
    else{
        if(x%11 <= 6 && x%11 > 0) ans = 2 * (x/11) + 1;
        else if(x%11 > 6) ans = 2 * (x/11) + 2;
        else ans = 2 * (x/11);
    }
    cout << ans << endl;
    return;
}

int main(){
    long long x;
    scanf("%lld",&x);
    solve(x);
    return 0;
}
