#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;

    long long int ans = n/2 * min({8*q, 4*h, 2*s, d});
    if(n % 2 == 1){
        ans += min({4*q, 2*h, s});
    }
    cout << ans << endl;
    return 0;
}