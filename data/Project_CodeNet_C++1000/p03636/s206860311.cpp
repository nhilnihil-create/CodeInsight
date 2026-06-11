#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    cout << s[0] << s.size() - 2 << s[(int)s.size() - 1] << endl;
}