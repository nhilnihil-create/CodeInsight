#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
#include <stdio.h>
typedef long long ll;
const int INF = 1e9+1;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;

int main() {
	int n;
	long long int tate = 0, yoko = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	sort(a.begin(), a.end(), greater<>());

	for (int i = 0; i < n-1; i++) {
		if (a.at(0) == a.at(1)) {
			tate = a.at(0);
			a.erase(a.begin(), a.begin() + 2);
			break;
		}
		else a.erase(a.begin());
	}
	if (tate == 0) {
		cout << 0 << endl;
		return 0;
	}
	int m = a.size();
	for (int i = 0; i <m ; i++) {
		if (a.at(0) == a.at(1)) {
			yoko = a.at(0);
			//a.erase(a.begin(), a.begin() + 2);
			break;
		}
		else a.erase(a.begin());
	}
	//cout << tate << " " << yoko << endl;
	cout << tate * yoko << endl;
	return 0;
}