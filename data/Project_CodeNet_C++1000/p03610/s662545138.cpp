#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    for(int i = 0; i < s.length(); i += 2) {
        cout << s[i];
    }

    cout << endl;
}