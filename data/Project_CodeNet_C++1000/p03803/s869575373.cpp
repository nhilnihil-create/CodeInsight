#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <new>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <tuple>
#include<map>

using namespace std;
int main() {
	vector<int> alice{ 2,3,4,5,6,7,8,9,10,11,12,13,1 };
	vector<int> bob{ 2,3,4,5,6,7,8,9,10,11,12,13,1 };

	int a, b;
	cin >> a >> b;

	int alice_p = 0, bob_p = 0;

	for (int i = 0; i < alice.size(); ++i) {
		if (a == alice.at(i)) {
			alice_p = i;
			//cout << "Alice_P = " << i << endl;
			break;
		}
	}

	for (int i = 0; i < alice.size(); ++i) {
		if (b == alice.at(i)) {
			bob_p = i;
			//cout << "Bob_P = " << i << endl;

			break;
		}
	}

	if (alice_p > bob_p) cout << "Alice" << endl;
	else if (alice_p < bob_p) cout << "Bob" << endl;
	else cout << "Draw" << endl;

}