#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+5;

const int mod = 1e9 +7;

long long n;

int main(){
    cin >> n;
    long long ans = 1;
    for(long long i = 1; i <= n; i++){
        ans *= i;
        ans %= mod;
    }
    cout << ans << "\n";
    return 0;
}
