#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    string s;
    cin >> s;
    cout << s[0] << s.length() - 2 << s[s.length()-1] << endl;

    return 0;
}