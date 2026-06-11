#include <bits/stdc++.h>

using namespace std;

int main() {
	
	string x;
	cin >> x;

	int i = 0;
	while (i < x.size() - 1) {
		if (x[i] =='S' && x[i + 1] == 'T') {
			x.erase(x.begin() + i+1);
			x.erase(x.begin() + i);
			i--;
			i--;

		}
		i++;
		if (i < 0) { i = 0; }
		if (x=="") { break; }
	}
	cout << x.size() << endl;
	return 0;
}