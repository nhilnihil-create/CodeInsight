#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    string s;
    cin >> s;
    int N = s.size();
    cout << s[0];
    cout << N-2;
    cout << s[N-1] << endl;
}
