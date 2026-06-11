#include "bits/stdc++.h"
using namespace std;

int main() {
	string A, B, C;
	cin >> A >> B >> C;
	string ans;
	ans += (char)(A[0] + ('A' - 'a'));
	ans += (char)(B[0] + ('A' - 'a'));
	ans += (char)(C[0] + ('A' - 'a'));
	cout << ans << endl;
	return 0;
}