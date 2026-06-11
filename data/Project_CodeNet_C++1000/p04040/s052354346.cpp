#include <iostream>
using namespace std;
#define M 1000000007
 
int modexp(int x, int e, int m) {
    long long ans = 1, p = x % m;
    while (e > 0) {
        if (e % 2 != 0) ans = ans * p % m;
        p = p * p % m;
        e >>= 1;
    }
    return ans;
}
 
long long fact[200001], facti[200001];
 
long long C(int n, int k) {
    if (n < 0 || k < 0 || k > n) return 0;
    return fact[n] * facti[k] % M * facti[n-k] % M;
}
 
int main(int argc, char** argv) {
    int h, w, a, b; cin >> h >> w >> a >> b;
    fact[0] = 1; facti[0] = 1;
    for (int i = 1; i <= h+w; i++) {
        fact[i] = fact[i-1] * i % M;
        facti[i] = modexp(fact[i], M-2, M);
    }
    long long ans = 0;
    for (int i = 1; i <= h-a; i++) ans += C(i+b-2, i-1) * C(h+w-b-i-1, h-i) % M;
    cout << ans % M << endl;
}