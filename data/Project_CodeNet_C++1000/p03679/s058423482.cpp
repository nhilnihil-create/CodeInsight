#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int X, A, B;
    cin >> X >> A >> B;
    if (B - A <= 0) cout << "delicious\n";
    else if (B - A <= X) cout << "safe\n";
    else cout << "dangerous\n";
}