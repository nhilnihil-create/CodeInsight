#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    for (int i = n - 1; i >= 0; i--) {
        if (s.substr(i, 7) == "dreamer")
            s.erase(s.begin() + i, s.begin() + i + 7);
        if (s.substr(i, 6) == "eraser")
            s.erase(s.begin() + i, s.begin() + i + 6);
        if (s.substr(i, 5) == "dream")
            s.erase(s.begin() + i, s.begin() + i + 5);
        if (s.substr(i, 5) == "erase")
            s.erase(s.begin() + i, s.begin() + i + 5);
    }

    if (s.empty())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
