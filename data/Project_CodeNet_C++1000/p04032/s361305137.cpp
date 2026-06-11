#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    for(int i = 0; i < s.length() - 1; i++) {
        if(s[i] == s[i + 1]) {
            cout << i + 1 << " " << i + 2 << endl;
            return 0;
        }
    }

    for(int i = 0; i < s.length() - 2; i++) {
        if(s[i] == s[i + 2]) {
            cout << i + 1 << " " << i + 3 << endl;
            return 0;
        }
    }

    cout << -1 << " " << -1 << endl;
}