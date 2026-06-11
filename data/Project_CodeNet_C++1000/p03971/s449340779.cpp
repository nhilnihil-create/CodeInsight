#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    int sum = a + b, cnt = 0, b_r = 1;
    for (int i = 0; i < n; i++) {
        if (s.at(i) == 'c') {
            cout << "No" << endl;
        } else {
            if (cnt < sum) {
                if (s.at(i) == 'a') {
                    cout << "Yes" << endl;
                    cnt++;
                } else if (s.at(i) == 'b' && b_r <= b) {
                    cout << "Yes" << endl;
                    cnt++;
                    b_r++;
                } else {
                    cout << "No" << endl;
                }
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
