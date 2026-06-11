#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n, odd = 0, even = 0;
    cin >> n;
    rep(i, n) {
        ll a;
        cin >> a;
        if (a & 1)
            odd++;
        else
            even++;
    }
    while (1) {
        bool changed = false;
        if (odd >= 2) {
            odd -= 2;
            even++;
            changed = true;
        }
        if (even >= 2) {
            even--;
            changed = true;
        }
        if (!changed) break;
    }
    puts(odd ^ even ? "YES" : "NO");
}