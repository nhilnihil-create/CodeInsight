#include <iostream>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	int ans = A + B;
	if (ans >= 10) cout << "error" << endl;
	else cout << ans << endl;
}