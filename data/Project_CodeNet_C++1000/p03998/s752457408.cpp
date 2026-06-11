#include <iostream>
#include <string>

using namespace std;

int main()
{
	string card[3];
	char c;
	char answer[3] = { 'A', 'B', 'C' };

	for (int i = 0; i < 3; i++) {
		cin >> card[i];
	}
	int index = 0;

	while (1) {
		for (int i = 0; i < 3; i++) {
			if (card[i].empty() && c - 97 == i) {
				cout << answer[i] << endl;
				return 0;
			}
		}
		c = card[index].at(0);
		card[index].erase(card[index].begin());
		index = c - 97;
	}
}