#include <iostream>
using namespace std;

const int INF = 1e9;

int main() {
    string s;
    cin >> s;
    int len = s.size();
    int ans = INF;
    for (int i = 0; i < 26; ++i) {
        char last = 'a' + i;
        int num1 = -1;
        int cnt1 = 0;
        for (int j = len - 1; j >= 0; --j) {
            if (s[j] == last) {
                num1 = cnt1;
                break;
            }
            else {
                cnt1++;
            }
        }
        int num2 = -1;
        int cnt2 = 0;
        for (int j = 0; j < len; ++j) {
            if (s[j] == last) {
                num2 = max(num2, cnt2);
                cnt2 = 0;
            }
            else cnt2++;
        }
        int num = max(num1, num2);
        if (num != -1) ans = min(ans, num);
    }
    cout << ans << endl;
}