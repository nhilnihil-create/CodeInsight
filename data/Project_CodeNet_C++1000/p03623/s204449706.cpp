#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int x, a, b;
    cin >> x >> a >> b;
    bool c = (abs(x-a)>abs(x-b));
    cout << (c?"B":"A") << endl;
}
