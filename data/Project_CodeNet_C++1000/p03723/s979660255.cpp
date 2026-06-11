#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
	int A, B, C, a, b, c, count = 0, key = 0;;

	cin >> A >> B >> C;

	while (A % 2 != 1 && B % 2 != 1 && C % 2 != 1) {
		
		if (key != A) {
			key = A;
		}
		else {
			cout << "-1";
			goto End;
		}

		a = A;
		b = B;
		c = C;
		
		A = (b + c) / 2;
		B = (c + a) / 2;
		C = (a + b) / 2;
		count++;
	}

	cout << count;

	End:

	return 0;
}
