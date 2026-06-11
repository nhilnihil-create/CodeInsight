#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    LL n, a, b, c, d, diff; cin >> n >> a >> b >> c >> d;
    diff = b - a;

    n--;
    for(LL i = 0; i <= n; i++) {
        if(diff <= (n-i) * d - i * c && diff >= (n-i) * c - i * d) {
            return cout << "YES", 0;
        }
    }    
    cout << "NO";
}