#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.length();
    long long ans = 0;
    for (int i = 0; i < (1 << len - 1); i++) {
        long long sum = 0;
        long long tmp = 1;
        for (int j = 0; j < len; j++) {
            sum += tmp * (s[len - 1 - j] - '0');
            if (!(i & (1 << j))) {
                tmp *= 10;
            } else {
                tmp = 1;
            }
        }
        ans += sum;
//        cout << sum << endl;
    }
    cout << ans << endl;
}
