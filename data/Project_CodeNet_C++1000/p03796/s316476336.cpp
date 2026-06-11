#include <bits/stdc++.h>
using namespace std;

int main(){
    long long MOD = 1000000007;
    long long n;
    cin >> n;
    long long ans = 1;
    for(int i=0; i<n; i++) {
        ans = (ans * (i + 1) ) % MOD;
    }

    cout << ans << endl;

}