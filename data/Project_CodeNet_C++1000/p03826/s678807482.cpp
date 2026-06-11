#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);

	int A, B, C, D; cin >> A >>B >> C >> D;

	if (A * B > C * D)cout << A * B << endl;
	else if (A * B < C * D)cout << C * D << endl;
	else cout << A * B << endl;
	return 0;
}

