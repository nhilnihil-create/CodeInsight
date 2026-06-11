#include <bits/stdc++.h>
 
using namespace std;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    cout << s[0] << s.length() - 2 << s[s.length() - 1] << endl;
}