
#include <bits/stdc++.h>
using namespace std;

#define li long long int
#define rep(i, to) for (li i = 0; i < ((li)(to)); i++)
#define repp(i, start, to) for (li i = (li)(start); i < ((li)(to)); i++)

#define F first
#define S second

typedef pair<li, li> PI;
map<PI, li> cnt;

int main(void)
{
	string a, b;
	cin >> a >> b;
	if (a == "D") {
		cout << (b == "D" ? "H" : "D") << endl;
	} else {
		cout << (b == "D" ? "D" : "H") << endl;
	}

	return 0;
}