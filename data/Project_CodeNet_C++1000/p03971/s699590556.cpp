#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b, t = 0, B = 0;
    string s;
    cin >> n >> a >> b >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'c') cout << "No\n";
        else if (s[i] == 'a') {
            if (t < a + b) {
                cout << "Yes\n";
                ++t;
            } else cout << "No\n";
        } else {
            if (t < a + b && B < b) {
                cout << "Yes\n";
                ++t;
                ++B;
            } else cout << "No\n";
        }
    }
    return 0;
}