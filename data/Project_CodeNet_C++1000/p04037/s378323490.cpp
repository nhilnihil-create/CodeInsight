#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template <class T>
inline void read(T &x) {
    x = 0;
    char c = getchar();
    bool f = 0;
    for (; !isdigit(c); c = getchar()) f ^= c == '-';
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    x = f ? -x : x;
}

template <class T>
inline void write(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    T y = 1;
    int len = 1;
    for (; y <= x / 10; y *= 10) ++len;
    for (; len; --len, x %= y, y /= 10) putchar(x / y + 48);
}

const int MAXN = 1e5;
int n, a[MAXN + 5];

int main() {
    read(n);
    for (int i = 1; i <= n; ++i) read(a[i]);
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1; i <= n; ++i)
        if (i + 1 > a[i + 1]) {//ÕÒµ½ÒÔÔ­µãÎª×óÏÂ½ÇµÄ×î´óÕý·½ÐÎ£¬ÆäÓÒÉÏ·½¶¥µãÎª (i, i) 
            int j = 0;
            for (; a[j + i + 1] == i; ++j);
            if (((a[i] - i) & 1) || (j & 1)) puts("First");
            else puts("Second");
            break;
        }
    return 0;
}