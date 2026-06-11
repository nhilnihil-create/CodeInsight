#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <functional>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

char S[100002];
char T[100002];
int Ssum[100001];
int Tsum[100001];
int V[256];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    V['A'] = 1;
    V['B'] = 2;
    cin >> S + 1 >> T + 1 >> q;
    int n = strlen(S + 1), m = strlen(T + 1);
    for (int i = 1; i <= n; ++i)
        Ssum[i] = Ssum[i - 1] + V[S[i]];
    for (int i = 1; i <= m; ++i)
        Tsum[i] = Tsum[i - 1] + V[T[i]];
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int s = Ssum[b] - Ssum[a - 1];
        int t = Tsum[d] - Tsum[c - 1];
        printf(s % 3 == t % 3 ? "YES\n" : "NO\n");
    }
    return 0;
}