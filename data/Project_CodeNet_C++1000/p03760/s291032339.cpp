#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	string O, E;
	cin >> O >> E;
	for (int i = 0; i < min(O.length(),E.length()); i++) {
		cout << O[i] << E[i];
	}
	if (O.length() < E.length()) {
		cout << E[E.length() - 1] << endl;
	}
	else if (O.length() == E.length()) {
		cout << endl;
	}
	else {
		cout << O[O.length() - 1] << endl;
	}
	return 0;
}