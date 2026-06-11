#include <iostream>

using namespace std;

int main() {
 	long long x;
  	cin >> x;
  	long long y = 0;
  	if (x >= 11) {
    	y += x / 11 *2;
    }
	if (x % 11 == 0) {
    } else if (x % 11 <= 6) {
    	y += 1;
    } else {
    	y += 2;
    }
  	cout << y;
  	return 0;
}