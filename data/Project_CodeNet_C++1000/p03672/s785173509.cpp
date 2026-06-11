#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;
    auto judge = [&]() {
        int n = s.size();
        if (n % 2 == 1) return false;
        return s.substr(0, n / 2) == s.substr(n / 2);
    };
    while (!s.empty()) {
        s.pop_back();
        if (judge()) {
            cout << s.size() << endl;
            break;
        }
    }
}
