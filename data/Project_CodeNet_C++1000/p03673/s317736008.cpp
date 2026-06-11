#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    deque<int> b;
    REP(i, n) {
        if (i % 2 == 0) b.push_back(a[i]);
        else b.push_front(a[i]);
    }
    if (n % 2 == 1) reverse(ALL(b));
    REP(i, n) cout << b[i] << " ";
    cout << endl;
}