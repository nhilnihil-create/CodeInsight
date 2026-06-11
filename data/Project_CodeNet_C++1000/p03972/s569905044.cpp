#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處

LL p[100005], q[100005];

int main() {
    LL w, h;
    cin >> w >> h;
    for (int i = 0; i < w; i++) {
        cin >> p[i];
    }
    p[w] = 999999999;
    sort(p, p + w);
    for (int i = 0; i < h; i++) {
        cin >> q[i];
    }
    q[h] = 999999999;
    sort(q, q + h);
    LL pi = 0, qi = 0;
    LL wc = 0, hc = 0;
    LL need = w * h + w + h;
    // printf("need %lld\n", need);
    LL ans = 0;
    while (true) {
        if (p[pi] < q[qi]) {
            LL num = h - hc + 1;
            // printf("use %d, %d\n", p[pi], num);
            if (num >= need) {
                ans += p[pi] * need;
                break;
            } else {
                ans += p[pi] * num;
                need -= num;
            }
            wc++;
            pi++;
        } else {
            LL num = w - wc + 1;
            // printf("use %d, %d\n", q[qi], num);
            if (num >= need) {
                ans += q[qi] * need;
                break;
            } else {
                ans += q[qi] * num;
                need -= num;
            }
            hc++;
            qi++;
        }
    }
    printf("%lld\n", ans);
}