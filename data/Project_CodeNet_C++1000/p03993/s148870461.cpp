#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    int like[n];
    rep(i,n) {
        int a;
        cin >> a;
        a--;
        like[i] = a;
    }
    int ans = 0;
    rep(i,n) if (i == like[like[i]]) ans++;
    ans /= 2;
    cout << ans << endl;
}