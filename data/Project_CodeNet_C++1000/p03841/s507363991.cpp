#include <iostream>
#include <cstdlib>

using namespace std;

#define MAXN 500

int ans[MAXN * MAXN + 1], u[MAXN * MAXN + 1], v[MAXN + 1];

inline void gata() {
    cout << "No\n";
    exit(0);
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        u[v[i]] = i;
    }

    int st = 1;
    for (int i = 1; i <= n * n; i++) if (u[i]) {
        int cnt = u[i] - 1;
        while (st < i && cnt > 0) {
            if (ans[st] == 0) ans[st] = u[i], cnt--;
            st++;
        }

        if (cnt > 0)
            gata();

        ans[i] = u[i];
    }

    int dr = n * n;
    for (int i = n * n; i > 0; i--) if (u[i]) {
        int cnt = n - u[i];
        while (dr > i && cnt > 0) {
            if (ans[dr] == 0) ans[dr] = u[i], cnt--;
            dr--;
        }

        if (cnt > 0)
            gata();
    }

    cout << "Yes\n";
    for (int i = 1; i <= n * n; i++)
        cout << ans[i] << ' ';

    return 0;
}
