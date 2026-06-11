#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string S1, S2, S3;
	cin >> S1;
	cin >> S2;
	cin >> S3;
	char card=S1[0];
	S1.erase(0, 1);
	while (true) {
		switch (card) {
		case'a':
			if (S1.size() == 0) { cout << 'A'; return 0; }
			card = S1[0];
			S1.erase(0, 1);
			break;

		case'b':
			if (S2.size() == 0) { cout << 'B'; return 0; }
			card = S2[0];
			S2.erase(0, 1);
			break;

		case'c':
			if (S3.size() == 0) { cout << 'C'; return 0; }
			card = S3[0];
			S3.erase(0, 1);
			break;
		}
	}


	return 0;

}