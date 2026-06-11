#include <bits/stdc++.h>

using namespace std;

#define fin cin
#define fout cout
//ifstream fin("x.in"); ofstream fout("x.out");

typedef long long i64;
const int mod = 1e9 + 7;

int main() {
    fin.sync_with_stdio(false); fin.tie(); fout.tie();

    int n;
    fin >> n;

    int ans = 1;
    int cnt = 0;
    for (int i = 1; i <= n; ++ i) {
        int x;
        fin >> x;

        if (x < 2 * (i - cnt) - 1) {
            ans = 1LL * ans * (i - cnt) % mod;
            ++ cnt;
        }
    }

    int r = n - cnt;
    for (int i = 1; i <= r; ++ i)
        ans = 1LL * ans * i % mod;
    fout << ans << "\n";

    return 0;
}
