#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	string N;
	cin >> N;
	if (N[0] == N[2]) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}