#include <iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;

int main() {
	int k, s;
	cin >> k >> s;

	int count = 0;
	int z;
	for (int x = 0; x <= k; x++) {
		for (int y = 0; y <= k; y++) {
			z = s - x - y;
			if (z > k) {
				continue;
			}
			else if (z >= 0) {
				count += 1;
			}
			else {
				continue;
			}
		}
	}
	
	cout << count << endl;

	return 0;
}