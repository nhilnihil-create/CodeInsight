#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;

    int japanese = 0, overseas = 0;
    for(int i = 0; i < n; ++i) {
        if (s[i] == 'c') {
            cout << "No\n";
        } else if (s[i] == 'a') {
            if (a + b > japanese) {
                cout << "Yes\n";
                ++japanese;
            } else {
                cout << "No\n";
            }
        } else {
            ++overseas;
            if (a + b > japanese && overseas <= b) {
                cout << "Yes\n";
                ++japanese;
            } else {
				cout << "No\n";
			}
        }
    }

    return 0;
}
