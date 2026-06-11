#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 100005;
const ll M = ll(1e9) + 7;

int n, p[N], a, b, c;
ll fa[N], fi[N];

ll pw(ll n, ll k){
    if(!k) return 1;
    return pw(n * n % M, k / 2) * (k % 2 ? n : 1) % M;
}

ll f(ll n, ll r){
    if(r < 0 || r > n) return 0;
    return fa[n] * fi[r] % M * fi[n - r] % M;
}

int main(){
    scanf("%d", &n); n++;
    fa[0] = 1;
    for(int i = 1; i <= n; i++) fa[i] = fa[i - 1] * i % M;
    fi[n] = pw(fa[n], M - 2);
    for(int i = n - 1; i >= 0; i--) fi[i] = fi[i + 1] * (i + 1) % M;
    for(int i = 1, x; i <= n; i++){
        scanf("%d", &x);
        if(p[x]){
            a = p[x] - 1;
            b = i - p[x] - 1;
            c = n - i;
            break;
        }
        p[x] = i;
    }
    for(int i = 1; i <= n; i++){
        printf("%lld\n", (f(a + b + c, i) + f(a + b + c, i - 2) +
            2 * f(a + b + c, i - 1) - f(a + c, i - 1) + M) % M);
    }
}