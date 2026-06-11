
#include <bits/stdc++.h>
using namespace std;

#define li long long int
#define rep(i, to) for (li i = 0; i < ((li)(to)); i++)
#define repp(i, start, to) for (li i = (li)(start); i < ((li)(to)); i++)

int main(void)
{
	string a, b;
	cin >> a >> b;
	if (a == "H") {
		cout << (b == "H" ? "H" : "D") << endl;
	} else {
		cout << (b == "H" ? "D" : "H") << endl;
	}

	return 0;
}