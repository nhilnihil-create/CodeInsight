#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    vector<int> A = {0, 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};
    cout << (A[x] == A[y] ? "Yes" : "No") << endl;
    return 0;
}