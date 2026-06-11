#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); ++i) {
        if (i%2 == 0) cout << s[i];
    }

    cout << endl;


    return 0;
}