#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <cstring>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

char in[200001];
int nxt[200001][26];
int mn[200002];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> in;
    int n = strlen(in);
    for (int i = 0; i < 26; ++i) nxt[n][i] = n;
    for (int i = n; i--; ) {
        for (int j = 0; j < 26; ++j) nxt[i][j] = nxt[i + 1][j];
        nxt[i][in[i] - 'a'] = i;
    }
    mn[n] = 1;
    for (int i = n; i--; ) {
        int mx = 0;
        for (int j = 0; j < 26; ++j) mx = max(mx, nxt[i][j]);
        mn[i] = mn[mx + 1] + 1;
    }
    for (int i = 0; i < n; ) {
        for (int j = 0; j < 26; ++j) if (mn[i] == mn[nxt[i][j] + 1] + 1) {
            printf("%c", 'a' + j);
            i = nxt[i][j] + 1;
            break;
        }
    }
    return 0;
}