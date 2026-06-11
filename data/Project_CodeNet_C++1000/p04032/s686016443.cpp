#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

template <class T>
inline void read(T &x) {
    x = 0;
    int f = 0;
    char ch = getchar();
    while (!isdigit(ch))    { f |= ch == '-'; ch = getchar(); }
    while (isdigit(ch))     { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }
    x = f ? -x : x;
    return;
}

std::string s;
int n;

int main() {
    std::cin >> s;
    n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == s[i + 1]) {
            printf("%d %d\n", i + 1, i + 2);
            return 0;
        }
        if (s[i] == s[i + 2]) {
            printf("%d %d\n", i + 1, i + 3);
            return 0;
        }
    }
    puts("-1 -1");
    return 0;
}