#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 1e9 + 7;

ll factorial(ll n){
    if(n == 0) return 1;
    return ((n % mod)* (factorial(n-1) % mod));
}

int main(void)
{
    ll N, M;
    cin >> N >> M;



    if(abs(N - M) > 1){
        cout << 0 << endl;
        return 0;
    }
    ll nfac = factorial(N);
    ll mfac = factorial(M);

    ll result = ((nfac % mod) * (mfac % mod))%mod;

    if(abs(N - M) == 0){
        cout << (result * 2)%mod << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
