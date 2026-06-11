#include <bits/stdc++.h>
#define int long long

using namespace std; 

const int maxn = 1e6; 
int n, m, cnt, p[maxn + 5], siz[maxn + 5], vis[maxn + 5], bel[maxn + 5];  
long long k, c[maxn + 5], ans[maxn + 5], na[maxn + 5], a[maxn + 5], x[maxn + 5], sta[maxn + 5]; 
int pos[maxn + 5]; 

vector <long long> v[maxn + 5]; 

signed main() {
    scanf("%lld", &n); 
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &x[i]); 
    }
    for (int i = 1; i <= n; i++) {
        a[i] = x[i] - x[i - 1]; 
    }
    scanf("%lld %lld", &m, &k); 
    for (int i = 1; i <= n; i++) {
        p[i] = i; 
    }
    for (int i = 1; i <= m; i++) {
        int t; 
        scanf("%lld", &t); 
        swap(p[t], p[t + 1]); 
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue ; 
        int x = i; 
        int top = 0; 
        while (!vis[x]) {
            vis[x] = 1; 
            sta[++top] = x; 
            x = p[x]; 
        }
        for (int j = 1; j <= top; j++) {
            na[sta[j]] = a[sta[(j + k - 1) % top + 1]]; 
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += na[i];
        printf("%lld.0\n", ans);  
    }
    // for (int i = 1; i <= n; i++) printf("%.9lf\n", (double)x[i]); 
    return 0; 
}