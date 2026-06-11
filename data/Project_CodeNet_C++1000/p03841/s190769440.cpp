#include <bits/stdc++.h>
using namespace std;

#define pos first
#define cnt second.first
#define num second.second
#define MP make_pair

const int MaxN = 510;
int n, x[MaxN], a[MaxN * MaxN];
pair <int, pair <int, int>> c[MaxN];
int ind;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        x[i]--;
        a[x[i]] = i;
        c[i - 1] = MP(x[i], MP(i - 1, i));
    }
    sort(c, c + n);
    ind = 0;
    for (int i = 0; i < n; i++) {
        for (; ind < c[i].pos && c[i].cnt > 0; ind++) {
            if (a[ind] == 0) {
                a[ind] = c[i].num;
                c[i].cnt--;
            }
        }
        if (c[i].cnt > 0) {
            cout << "No";
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
        c[i - 1] = MP(x[i], MP(n - i, i));
    sort(c, c + n);
    ind = n*n - 1;
    for (int i = n - 1; i >= 0; i--) {
        for (; ind > c[i].pos && c[i].cnt > 0; ind--) {
            if (a[ind] == 0) {
                a[ind] = c[i].num;
                c[i].cnt--;
            }
        }
        if (c[i].cnt > 0) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes\n";
    for (int i = 0; i < n * n; i++)
        cout << a[i] << " ";
    return 0;
}
