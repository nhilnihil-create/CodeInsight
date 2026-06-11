#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<iomanip>

using namespace std;

int main(void) {
	int x;
	cin >> x;
	int sum = 0;
	for (int i = 0; i <= x; i++) {
		sum += i;
		if (sum >= x) {
			cout << i;
			return 0;
		}
	}
	return 0;
}