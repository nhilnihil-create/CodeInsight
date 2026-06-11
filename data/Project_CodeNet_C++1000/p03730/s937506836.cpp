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


int main() {
	long long int A, B, C;
	string ans = "NO";

	cin >> A >> B >> C;
	
	for (int i = 1; i <= B; i++) {
		if (A * i % B == C) {
			ans = "YES";
			break;
		}
	}

	cout << ans;

	return 0;
}
