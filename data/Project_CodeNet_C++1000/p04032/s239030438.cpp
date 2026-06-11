#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define ff first
#define ss second
#define endl '\n'

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	string s;
	cin >> s;

	int a, b, c, d;
	a = (1 << (s[0] - 'a'));

	for (int i = 1; i < s.size(); ++i) {
		b = (1 << (s[i] - 'a'));
		if (a & b) {
			cout << i << ' ' << i+1 << endl;
			return 0;
		}

		a = b;
	}

	a = (1 << (s[0] - 'a'));
	b = (1 << (s[1] - 'a'));
	for (int i = 2; i < s.size(); ++i) {
		c = (1 << (s[i] - 'a'));
		if ((a & b) || (b & c) || (a & c)) {
			cout << i-1 << ' ' << i+1 << endl;
			return 0;
		}

		a = b;
		b = c;
	}

	if (s.size() < 3) {
		cout << -1 << ' ' << -1 << endl;
		return 0;
	}

	a = (1 << (s[0] - 'a'));
	b = (1 << (s[1] - 'a'));
	c = (1 << (s[2] - 'a'));
	for (int i = 3; i < s.size(); ++i) {
		d = (1 << (s[i] - 'a'));
		if ((a & b & (a | b)) || (a & c & (b | d)) || (a & d & (b | c)) || (b & c & (a | d)) || (b & d & (a | c)) || (c & d & (a | b))) {
			cout << i-2 << ' ' << i+1 << endl;
			return 0;
		}

		a = b;
		b = c;
		c = d;
	}

	cout << -1 << ' ' << -1 << endl;
	return 0;
}