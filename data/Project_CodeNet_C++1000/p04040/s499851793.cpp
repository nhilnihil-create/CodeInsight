#include<bits/stdc++.h>
 using namespace std;
 typedef long long LL;
 const int P = 1000000007;
 LL f[1000001], v[1000001];
 LL rp(LL now, int k) 
 {
     LL will = 1;
     for (; k; k >>= 1, now *= now, now %= P) 
     {
         if (k & 1) will *= now, will %= P;
     }
     return will;
 }
 LL C(int n, int m) 
 {
     if(n < m) return 0;
     if(m == 0) return 1;
     return f[n] * rp(f[m], P - 2) % P * rp(f[n - m], P - 2) % P;
 }
 void init()
 {
     f[0] = 1; v[0] = 1;
     for (int i = 1; i <= 1000000; i++) //1e6以  内的组合数
     {
         f[i] = f[i - 1] * i % P;
     }
 }
 int main() 
 {
    init();
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    LL ans = 0;
    for(int i = b + 1; i <= w; i++) {
       // printf("C(%d, %d)\n", (h - a) + (b + i) - 2, h - a - 1);
        // printf("C(%d, %d)\n", a + (w - b - i + 1), a - 1);
        LL tmp = C((h - a) + i - 2, i - 1) * C(a + (w - i + 1) - 2, w - i) % P;
        ans = (ans + tmp) % P;
    }
    cout << ans << endl;
 }