#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

int main() {
    int n; cin >> n;
    vector<int> a(n);
    REP(i, n) {cin >> a[i]; --a[i];}

    int ans = 0;
    REP(i, n)
        if(a[a[i]] == i && a[i] > i) ++ans;

    cout << ans << endl;

    return 0;
}