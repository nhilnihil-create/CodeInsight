#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a,a+3);
    cout << a[0] +a[1] << endl;
}
