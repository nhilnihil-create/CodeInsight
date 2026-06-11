#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int a, b, c, d;
	int start, finish;
	cin >> a >> b >> c >> d;
	start = max(a, c);
	finish = min(b, d);
	if (start < finish) cout << finish - start;
	else cout << '0';
}