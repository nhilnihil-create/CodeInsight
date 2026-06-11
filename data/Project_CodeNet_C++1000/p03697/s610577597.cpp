#include <iostream>
#include <cstdio>
using namespace std;

int x, y;
int main() {
	cin >> x >> y;
	if(x+y < 10) cout << x+y;
	else cout << "error";
	return 0;
}
