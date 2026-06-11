/*
[arc072] D - Alice&Brown
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

ll X, Y;

bool solve() { return abs(X - Y) > 1; }

int main() {
    cin >> X >> Y;

    cout << (solve() ? "Alice" : "Brown") << endl;

    return 0;
}
