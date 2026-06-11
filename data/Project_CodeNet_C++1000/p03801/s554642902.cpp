#include <bits/stdc++.h>
using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int N;
int in[110000], idx[110000], ans[110000];;
bool nz[110000];

signed main() {
    cin >> N;
    for (int i = 1; i <= N; i++)cin >> in[i];

    int m = -1;
    for (int i = 0; i <= N; i++) {
        nz[i] = in[i] > m;
        m = max(m, in[i]);
    }

    for (int i = 0; i <= N; i++)idx[i] = i;
    stable_sort(idx, idx + N + 1, [](int a, int b) {
        return in[a] > in[b];
    });

    int prev = 101000, sum = 0;
    idx[101000] = 101000;
    for (int i = 0; i <= N; i++) {
        if (nz[idx[i]]) {
            ans[idx[prev]] = sum - i * in[idx[i]];
            sum = (i + 1) * in[idx[i]];
            prev = i;
        } else {
            sum += in[idx[i]];
        }
    }
    for (int i = 1; i <= N; i++)cout << ans[i] << endl;
}
