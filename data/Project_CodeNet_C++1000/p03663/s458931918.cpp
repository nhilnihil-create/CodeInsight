#include <bits/stdc++.h>
using namespace std;

int main() {
    auto query = [&]() {
        long long cur = 10;
        for (int i = 1; i <= 10; i++) {
            printf("? %lld\n", cur), fflush(stdout);
            char s[2]; scanf("%s", s);
            if (s[0] == 'N') return i;
            cur = cur * 10;
        }
        cur = 9;
        for (int i = 1; i <= 10; i++) {
            printf("? %lld\n", cur), fflush(stdout);
            char s[2]; scanf("%s", s);
            if (s[0] == 'Y') return i;
            cur = cur * 10 + 9;
        }
    };
    int len = query(), sum = 0;
    if (len == 10) printf("! %d\n", 1000000000), exit(0);
    for (int i = 1; i <= len; i++) {
        int l = (i == 1 ? 1 : 0), r = 9, pw = 1, ans = 0;
        for (int j = 1; i + j <= len; j++) pw *= 10;
        int tmp = i < len ? 9 : 0;
        for (int j = 1; i + j < len; j++) tmp = tmp * 10 + 9;
        while (l <= r) {
            int mid = (l + r) >> 1;
            printf("? %lld\n", (sum + mid * pw + tmp) * 10LL), fflush(stdout);
            char s[2]; scanf("%s", s);
            if (s[0] == 'Y') r = (ans = mid) - 1;
            else l = mid + 1;
        }
        sum += pw * ans;
    }
    printf("! %d\n", sum);
    return 0;
}