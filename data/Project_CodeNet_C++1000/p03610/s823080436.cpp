#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i += 2) {
        cout << s[i];
    }
    cout << endl;
    return 0;
}