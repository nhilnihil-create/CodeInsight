#include <iostream>
using namespace std;

int main() {
	int X, A, B;
	cin >> X >> A >> B;
	if (A >= B) cout << "delicious" << endl;
	else cout << (B - A <= X ? "safe" : "dangerous") << endl;
}
