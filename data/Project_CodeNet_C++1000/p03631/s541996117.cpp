#include<bits/stdc++.h>
using namespace std;
int main () {
    int a;
    cin >> a;
    string s = to_string(a);
    vector<int> b(a / 2);
    for (int i = 0; i < a / 2; i++) {
        b[i] = s[i];
    }
    reverse(s.begin(), s.end());
    for (int i = 0; i < a / 2; i++) {
        if (b[i] != s[i]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}