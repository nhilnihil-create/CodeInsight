#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < int(n); i++)
#define FOR(i,n,m) for(int i = int(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 1e18 + 1;

int main() {
    int n; cin >> n;
    vector<int> p(n);
    REP(i, n) scanf("%d", &p[i]);
    vector<int> a(n,1),b(n,1);
    REP(i, n) {
        a[p[i] - 1] += i;
        b[p[i] - 1] += i;
    }
    REP(i, n-1) {
        a[i + 1] += a[i];
        b[n - i - 2] += b[n - i - 1];
    }
    REP(i, n) printf("%d ", a[i]);
    printf("\n");
    REP(i, n) printf("%d ", b[i]);
    printf("\n");
    return 0;
}