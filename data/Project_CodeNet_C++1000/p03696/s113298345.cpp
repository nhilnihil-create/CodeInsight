#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int cur = 0, left = 0;
    for (char i : s) {
        if (i == '(') cur++;
        else {
            if (cur == 0) left++;
            else cur--;
        }
    }
    for (int i = 0; i < left; ++i) cout << "(";
    cout << s;
    for (int i = 0; i < cur; ++i) cout << ')';
    cout << endl;
}
