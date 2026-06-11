#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
double PI = 3.1415926535897932;
const double EPS = 1e-9;
const ll MOD = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

int n;
int a[100];
int cnt[101];

int main() {
    cin >> n;
    rep(i,n) cin >> a[i];
    rep(i,n) cnt[a[i]]++;
    sort(a, a+n);
    int M = a[n-1];
    if (a[0] < (M+1)/2) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (M%2 == 0) {
        if (cnt[M/2] != 1) {
            cout << "Impossible" << endl;
            return 0;
        }
    } else {
        if (cnt[(M+1)/2] != 2) {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    for (int i = (M+1)/2+1; i <= M; i++) {
        if (cnt[i] < 2) {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
}