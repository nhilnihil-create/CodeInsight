#include <iostream>
using namespace std;

int main() {
	int X, tmp = 0, i = 0;
	cin >> X;
	while(1){  // minimum i such that 1 + 2 + ... + i >= x
		i++;
		tmp += i;
		if(tmp >= X) break;
	}
	cout << i << endl;
}