#include <iostream>
using namespace std;

int main(){
	long long a, b, x; cin >> a >> b >> x;
	a = (a + x - 1) / x * x; b = b / x * x;
	cout << (b - a) / x + 1 << '\n';
}
