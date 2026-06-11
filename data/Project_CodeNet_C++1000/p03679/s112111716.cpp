#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int X, A, B;
    cin >> X >> A >> B;
    if (A >= B) {
        cout << "delicious" << endl;
    } else if (B - A <= X) {
        cout << "safe" << endl;
    } else {
        cout << "dangerous" << endl;
    }
}
