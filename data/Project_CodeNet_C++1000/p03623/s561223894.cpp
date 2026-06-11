#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(s) (int)s.size()

int main() {
    int x, a, b;
    cin >> x >> a >> b;
    if (abs(x - a) <= abs(x - b)) cout << "A";
    else cout << "B";
}