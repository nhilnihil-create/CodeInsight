#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

string S;

int main() {
	cin >> S; int dep = 0, mindep = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'S') dep++;
		else dep--;
		mindep = min(mindep, dep);
	}
	cout << -mindep + (dep - mindep) << endl;
	return 0;
}