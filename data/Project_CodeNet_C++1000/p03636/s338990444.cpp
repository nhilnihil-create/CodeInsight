#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, s1, s2;
    cin >> s;
    string res;

    int num = s.size() -2;
    s1 = s[0];
    s2 = s[s.size() -1];

    cout << s1 + to_string(num) + s2 << endl;
}