#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    string s;
    cin >> s;

    int length = s.size();
    cout << s.at(0) << length - 2 << s.at(length - 1) << endl;
    return 0;
}