#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}
const int MOD = 1000000007;


int main() {
    int n; cin >> n;
    int ans = 0;
    for(int i = 0;i < n;++i){
        int a,b; cin >> a >> b;
        ans += (b-a)+1;
    }
    cout << ans;
}


