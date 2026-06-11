#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ret, lap = 0; scanf("%d", &n);
    char s[n], t[n];  scanf("%s%s", s, t);

    for (int i = 0; i <= n; i++) {
        bool tf = true;
        int k = 0;
        for (int j = i; j < n; j++) {
            tf = (s[j] == t[k++]);
            if (!tf) break;
        }
        if (tf) {ret = 2 * n - k; break;}
    } 

    printf("%d\n", ret);
    return 0;
}