#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    cout << s[0] + to_string(s.size() - 2) + s[s.size() - 1] << endl;
}
