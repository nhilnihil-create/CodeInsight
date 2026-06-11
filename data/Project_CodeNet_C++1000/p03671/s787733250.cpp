#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int bells[3];
    rep(i,3) cin >> bells[i];
    sort(bells, bells+3);
    cout << bells[0] + bells[1] << endl;
}