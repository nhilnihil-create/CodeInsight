#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;
using ll = long long;

int main() {
	int a,b;
	cin >> a >> b;
	string n;
	for (int i = 0; i < b + 2; i++) {
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < a; i++) {
		cin >> n;
		cout << "#"<<n <<"#"<< endl;
	}
	for (int i = 0; i < b + 2; i++) {
		cout << "#";
	}
	cout << endl;
}
