#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    string s;
    cin >> s;
    int first = 0, last = s.size() - 1;
    cout << s[0] << s.size() - 2 << s[last] << endl;
    return 0;
}