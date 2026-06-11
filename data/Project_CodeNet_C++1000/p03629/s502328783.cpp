#include <bits/stdc++.h>
using namespace std;

int n, f[26], from[26], nxt[210000];
char s[210000];

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = n + 1; i <= n + 26; i++) {
        from[i - n - 1] = i, s[i] = 'a' + i - n - 1;
    }
    for (int i = n; i; i--) {
        for (int j = 0; j < 26; j++) {
            if (f[j] == *min_element(f, f + 26)) {
                f[s[i] - 'a'] = f[j] + 1;
                nxt[i] = from[j], from[s[i] - 'a'] = i; break;
            }
        }
    }
    int fir = from[min_element(f, f + 26) - f];
    string str;
    while (fir) {
        str.push_back(s[fir]), fir = nxt[fir];
    }
    cout << str << endl;
    return 0;
}