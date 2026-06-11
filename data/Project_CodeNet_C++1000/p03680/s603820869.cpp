#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;
using ll = long long;

int main() {
  
	int N;
	cin >> N;
	vector<int> vec(N + 1);

	for (int i = 1; i < N+1; i++) {

		cin >> vec.at(i);

 }
	int count=0;
	int x = 1;/*ボタン*/
	int y;/*次のボタン*/

	for (int i = 1; i < N+1; i++) {

		y = vec.at(x);
		x = y;
		count++;

		if (x == 2) {
			cout << count << endl;
			return 0;
		}

		else if (i == N) {

			cout << -1 << endl;
			return 0;
		}

	}


	return 0;

}
