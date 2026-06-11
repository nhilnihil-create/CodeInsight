#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
char S[maxn], T[maxn];
int sum_s[maxn], sum_t[maxn];
int main() {
#ifdef LDT
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> (S + 1) >> (T + 1) >> q;
    int n = strlen(S + 1), m = strlen(T + 1);
    for (int i = 1; i <= n; ++i)
        sum_s[i] = sum_s[i - 1] + (S[i] == 'A' ? +1 : -1);
    for (int i = 1; i <= m; ++i)
        sum_t[i] = sum_t[i - 1] + (T[i] == 'A' ? +1 : -1);
    
    for (int i = 1; i <= q; ++i) {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        int s1 = sum_s[v] - sum_s[u - 1];
        int s2 = sum_t[r] - sum_t[l - 1];
        s1 %= 3;
        s2 %= 3;
        s1 += 3;
        s2 += 3;
        if (s1 % 3 == s2 % 3)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}