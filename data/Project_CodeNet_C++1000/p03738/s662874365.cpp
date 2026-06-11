#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	string A, B;
	cin >> A >> B;

	string ans = "";
	if (A.size()==B.size()) {
		if (A>B) ans = "GREATER";
		else if (A<B) ans = "LESS";
		else ans = "EQUAL";
	}
	else if (A.size() > B.size()) {
		ans = "GREATER";
	}
	else {
		ans = "LESS";
	}

	cout << ans << endl;
}