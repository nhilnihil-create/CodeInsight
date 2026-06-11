#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
const double EPS = 1e-9;
const ll MOD = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

int n, x;
int ans[200000];
bool saw[200000];

int main() {
    cin >> n >> x;
    if (n == 2) {
        if (x != 2) {
            cout << "No" << endl;
            return 0;
        }
        cout << "Yes" << endl;
        cout << 1 << endl << 2 << endl << 3 << endl;
        return 0;
    }
    if (x == 1 || x == 2*n-1) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    ans[n-1] = x-1;
    ans[n] = x;
    ans[n+1] = x+1;
    int num = 1;
    for (int i = 1; i <= 2*n-1; i++) {
        if (abs(i-n) <= 1) continue;
        if (num == x-1) num += 3;
        ans[i] = num;
        num++;
    }
    for (int i = 1; i <= 2*n-1; i++) cout << ans[i] << endl;
}