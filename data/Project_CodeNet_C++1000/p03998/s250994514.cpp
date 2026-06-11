#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_card_game_easy(void) {
	string a, b, c;
	cin >> a >> b >> c;
	int ptr_a = 0, ptr_b = 0, ptr_c = 0;
	char turn = 'a';

	string winner;
	while (true) {
		if (turn == 'a') {
			if (ptr_a == a.size()) {
				winner = 'A';
				break;
			}
			turn = a[ptr_a++];
		}
		else if (turn == 'b') {
			if (ptr_b == b.size()) {
				winner = 'B';
				break;
			}
			turn = b[ptr_b++];
		}
		else {
			if (ptr_c == c.size()) {
				winner = 'C';
				break;
			}
			turn = c[ptr_c++];
		}
	}
	cout << winner << endl;
}

int main()
{
	b_card_game_easy();
    return 0;
}