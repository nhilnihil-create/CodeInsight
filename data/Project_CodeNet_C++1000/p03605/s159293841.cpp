#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int N;
	cin >> N;
	int ten = N / 10;
	int one = N % 10;
	if (ten == 9 || one == 9) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}