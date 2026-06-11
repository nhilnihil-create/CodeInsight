#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int A, B;
    cin >> A >> B;
    bool c1 = A%3 == 0;
    bool c2 = B%3 == 0;
    bool c3 = (A+B)%3 == 0;
    cout << ((c1||c2||c3)?"Possible":"Impossible") << endl;
}
