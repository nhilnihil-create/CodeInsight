#include <iostream>
using namespace std;

int main() {
	const int G[13] = { 0,1,3,1,2,1,2,1,1,2,1,2,1 };
	int x, y;
	cin >> x >> y;
	cout << (G[x] == G[y] ? "Yes" : "No") << endl;
}