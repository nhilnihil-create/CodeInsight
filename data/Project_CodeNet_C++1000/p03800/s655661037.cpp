#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<deque>
#include<algorithm>
#include<math.h>

using namespace std;
int main() {
	
	//D
	int n;
	string s;
	cin >> n;
	cin >> s;
	s[n] = s[0];
	//SS, SW, WS, WW
	int i, j;
	char t[100003];
	for (j = 0; j < 4; j++) {
		if (j == 0) {
			t[0] = 'S';
			t[1] = 'S';
		}
		else if (j == 1) {
			t[0] = 'S';
			t[1] = 'W';
		}
		else if (j == 2) {
			t[0] = 'W';
			t[1] = 'S';
		}
		else if (j == 3) {
			t[0] = 'W';
			t[1] = 'W';
		}
		for (i = 1; i <= n; i++) {
			if (t[i] == 'S') {
				if (s[i] == 'o') {
					t[i + 1] = t[i - 1];
				}
				else if (s[i] == 'x') {
					if (t[i - 1] == 'S') {
						t[i + 1] = 'W';
					}
					else {
						t[i + 1] = 'S';
					}
				}
			}
			else if (t[i] == 'W') {
				if (s[i] == 'x') {
					t[i + 1] = t[i - 1];
				}
				else if (s[i] == 'o') {
					if (t[i - 1] == 'S') {
						t[i + 1] = 'W';
					}
					else {
						t[i + 1] = 'S';
					}
				}
			}
		}
		if (t[0] == t[n] && t[1] == t[n + 1]) {
			for (i = 0; i < n; i++) {
				cout << t[i];
			}
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
	
	//C
	/*long long int n, m;
	cin >> n >> m;
	if (n >= m / 2) {
		cout << m / 2 << endl;
		return 0;
	}
	else {
		cout << n + (m - 2 * n) / 4 << endl;
		return 0;
	}
	*/
}