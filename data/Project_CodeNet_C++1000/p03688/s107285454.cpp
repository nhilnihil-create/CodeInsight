// me & god
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

const int N = 1e5 + 10;

int n, a, b, na, nb;
vector <int> v;

int main() {
	ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	set <int> s;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		s.insert(a);
		v.push_back(a);
	}
	if (s.size() > 2)
		cout << "No";
	else if (s.size() == 2) {
		vector <int> l;
		for (auto x: s)
			l.push_back(x);
		a = l[0];
		b = l[1];
		if (b - a != 1)
			cout << "No";
		else {
			na = 0, nb = 0;
			for (auto x: v) {
				if (x == a)
					na++;
				else
					nb++;
			}
			int k = b;
			k -= na;
			if (nb >= 2 * k && k > 0)
				cout << "Yes";
			else
				cout << "No";
		}
	}
	else {
		vector <int> l;
		for (auto x: s)
			l.push_back(x);
		a = l[0];
		if (n == a + 1 || n >= a * 2)
			cout << "Yes";
		else
			cout << "No";
	}
	return 0;
}