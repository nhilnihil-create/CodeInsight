#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int w, h; cin >> w >> h;
    int p[w], q[h];
    for (int i = 0; i < w; i++) cin >> p[i];
    for (int i = 0; i < h; i++) cin >> q[i];
    sort(p, p+w); sort(q, q+h);
    int i = 0, j = 0;
    long long ans = 0;
    while (i < w || j < h) {
        if (i < w && (j == h || p[i] <= q[j]))
            ans += (long long)p[i++] * (h - j + 1);
        else
            ans += (long long)q[j++] * (w - i + 1);
    }
    cout << ans << endl;
}
