#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
    int g[12] = {1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};
    int x, y;
    cin >> x >> y;
    cout << (g[x-1] == g[y-1] ? "Yes" : "No") << endl;
    return 0;
}