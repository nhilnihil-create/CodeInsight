#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
const int tam = 1e6;
long long f[tam], finv[tam];

/*
    5 5 2 2
    o o o o o
    o o o o o
    o o o o o
    x x o o o
    x x o o o
*/

long long exp( long long b, long long e ) {
    long long ans = 1;
    while( e ) {
        if( e&1 ) {
            ans = (ans*b)%mod;
        }
        b = (b*b)%mod;
        e >>= 1;
    }
    return ans;
}

long long NcK( long long N, long long K ) {
    return ( (f[N]*finv[N-K])%mod * finv[K] )%mod;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    f[0] = finv[0] = 1;
    for( int i = 1; i < tam; i++ ) {
        f[i] = (f[i-1]*i)%mod;
        finv[i] = exp( f[i], mod-2 );
    }
    int w, h, a, b;
    cin >> h >> w >> a >> b;
    long long ans = 0;
    for( int x = b; x < w; x++ ) {
        long long y = h - a - 1, x1 = w-x-1;
        long long temp = ( NcK(y+x, x) * NcK( a-1 + x1, x1 ) )%mod;
        ans = (ans+temp)%mod;
    }
    cout << ans << '\n';
    return 0;
}