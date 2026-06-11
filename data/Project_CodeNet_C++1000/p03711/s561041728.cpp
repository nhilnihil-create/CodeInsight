#include <iostream>
using namespace std;

int main() {
	int group[3][12] = {{2}, {4,6,9,11}, {1,3,5,7,8,10,12}};
	int x, y;
	cin >> x >> y;

	string ans = "No";
	for(int i = 0; i < 3; i++) {
		for (int j = 0; j < 12; j++) {
			if (group[i][j] == x) {
				for (int k = 0; k < 12; k++) {
					if (group[i][k] == y) {
						ans = "Yes";
						break;
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}