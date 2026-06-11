#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    string ans[s.size()];

    int win = 0;
    int grade_b = 1;
    int i;
    for(i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'a') {
            if (win < a + b) {
                ans[i] = "Yes";
                win++;
            }
            else {
                ans[i] = "No";
            }
        }
        else if (s[i] == 'b') {
            if (win < a + b && grade_b <= b) {
                ans[i] = "Yes";
                win++;
            }
            else {
                ans[i] = "No";
            }
            grade_b++;
        }
        else {
            ans[i] = "No";
        }
    }

    for(i = 0; i < (int)s.size(); i++) {
        cout << ans[i] << endl;
    }
}
