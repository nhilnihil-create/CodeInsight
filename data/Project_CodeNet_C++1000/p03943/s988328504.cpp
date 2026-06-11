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

int a[3];
int main() {
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if (a[0] + a[1] == a[2])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
