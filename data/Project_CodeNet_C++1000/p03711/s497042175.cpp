#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int x, y;
    cin >> x >> y;
    vector<int> a = {0, 2, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0};
    cout << (a[x - 1] == a[y - 1] ? "Yes" : "No") << endl;
    return 0;
}