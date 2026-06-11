#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 55;
int n, m, a, b;
int CNT[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        CNT[a]++;
        CNT[b]++;
    }
    for (int i = 1; i <= n; ++i) {
        cout << CNT[i] << endl;
    }
    return 0;
}
