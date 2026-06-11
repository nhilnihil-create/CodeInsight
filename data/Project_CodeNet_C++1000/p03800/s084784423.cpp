#include <iostream>
#include <functional>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    for (char i : {'S', 'W'}) {
        for (char j : {'S', 'W'}) {
            string result(n, 0);
            result[0] = i;
            result[1] = j;
            for (int k = 2; k < n; k++) {
                if (s[k - 1] == 'o' && result[k - 1] == 'S' || s[k - 1] == 'x' && result[k - 1] == 'W') {
                    result[k] = result[k - 2];
                } else {
                    if (result[k - 2] == 'S') {
                        result[k] = 'W';
                    } else {
                        result[k] = 'S';
                    }
                }
            }
            auto valid = [&](int i) {
                return (s[i] == 'o' && result[i] == 'S' || s[i] == 'x' && result[i] == 'W') && result[(i - 1 + n) % n] == result[(i + 1 + n) % n] || (s[i] == 'o' && result[i] == 'W' || s[i] == 'x' && result[i] == 'S') && result[(i - 1 + n) % n] != result[(i + 1 + n) % n];
            };
            if (valid(n - 1) && valid(0)) {
                cout << result;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}
