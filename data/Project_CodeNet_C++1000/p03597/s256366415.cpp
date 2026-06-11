#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, a;
	cin >> n >> a;
	int ans =  pow(n, 2) - a;
	cout << ans << endl;
	return 0;
}