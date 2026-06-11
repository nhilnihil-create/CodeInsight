#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    char a, b;
    cin >> a >> b;

    char ans;
    if (a == 'H' && b == 'H') ans = 'H';
    if (a == 'H' && b == 'D') ans = 'D';
    if (a == 'D' && b == 'H') ans = 'D';
    if (a == 'D' && b == 'D') ans = 'H';

    cout << ans << endl;

    return 0;
}