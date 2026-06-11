#include <bits/stdc++.h>
#define int long long

using namespace std; 

const int maxn = 1e6; 

int n; 
int ans, sum; 
int op[maxn + 5], a[maxn + 5]; 

signed main() {
    scanf("%lld", &n); n--; 
    scanf("%lld", &sum);
    for (int i = 1; i <= n; i++) {
        char s[2]; 
        scanf("%s %lld", s, &a[i]); 
        if (s[0] == '-') op[i] = -1; 
        else op[i] = 1; 
        sum += a[i];
    } 
    for (int i = 1; i <= n; i++) {
        if (op[i] != -1) continue ; 
        int pos = i + 1, s = a[i]; 
        while (op[pos] == 1 && pos <= n) {
            s += a[pos]; pos++; 
        }
        ans = max(ans, sum - 2 * s); 
        sum -= 2 * a[i]; 
    }
    if (ans == 0) ans = sum; 
    cout << ans << '\n'; 
    return 0; 
}