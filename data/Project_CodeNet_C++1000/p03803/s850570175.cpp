#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;

	string w;
	if (A == B) {
		w = "Draw";
	}
	else if (B == 1) {
		w = "Bob";
	}
	else if (A == 1) {
		w = "Alice";
	}
	else if (A > B) {
		w = "Alice";
	}
	else if (A < B) {
		w = "Bob";
	}

	cout << w << endl;
}