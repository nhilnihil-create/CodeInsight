#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    set<int> a;
    int x, y, z;
    cin >> x >> y >> z;
    a.insert(x);
    a.insert(y);
    a.insert(z);

    cout << a.size() << endl;

    return 0;
}