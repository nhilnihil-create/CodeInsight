#include <bits/stdc++.h>

using namespace std;

char s[100005];
int main() {
    scanf("%s", s);
    int k;
    scanf("%d", &k);
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        int req = 26 - (s[i] - 'a');
        if (req <= k && s[i] != 'a') s[i] = 'a', k -= req;
    }

    k %= 26;
    s[n - 1] += k;

    printf("%s\n", s);

    return 0;
}
