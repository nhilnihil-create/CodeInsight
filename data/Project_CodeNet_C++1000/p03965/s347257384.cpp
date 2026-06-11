#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int res = 0, cnt_g = 0, cnt_p = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'g') {
            if (cnt_p < cnt_g) {
                res++;
                cnt_p++;
            } else {
                cnt_g++;
            }
        } else {
            if (cnt_p < cnt_g) {
                cnt_p++;
            } else {
                res--;
                cnt_g++;
            }
        }
    }
    cout << res << endl;
    return 0;
}