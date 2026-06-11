#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>


using namespace std;


int main(){
	int ans, n;
	string S;
	cin >> S;

	for (int i = 0; i < S.size(); i++) {
		S.erase(S.size() - 1);
		n = S.size();

		if (n == 2) {
			ans = 2;
		}
		
		else if (n % 2 == 0) {

			if (S.substr(0, n / 2) == S.substr(n / 2, n)) {
				ans = n;
				break;
			}
		}
	}

	cout << ans;

	return 0;
}
