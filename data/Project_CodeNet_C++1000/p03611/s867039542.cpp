#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int const MAX = 100005;
int a[MAX];

int main() {
    int n;
    cin >> n;
    rep(i, n) {
        int x;
        cin >> x;
        a[x - 1]++;
        a[x]++;
        a[x + 1]++;
    }

    sort(a, a + MAX, greater<int>());

    cout << a[0] << endl;
    return 0;
}
