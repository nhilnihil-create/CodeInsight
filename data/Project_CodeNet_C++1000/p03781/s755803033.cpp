#include<iostream>
#include<math.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<deque>
using namespace std;
int main() {

	int x;
	cin >> x;
	int i;
	for (i = 0; i <= x; i++) {

		if (((i * (i - 1)) / 2 < x) && (x <= (i * (i + 1)) / 2)) {
			cout << i << endl;
			return 0;
		}

	}
	return 0;

}