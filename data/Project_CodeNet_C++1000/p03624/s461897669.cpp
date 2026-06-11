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
	string t;
	char s[1000000];
	vector<int> a(27);
	cin >> s;
	t = s;
	for (int i = 0; i <t.size() ; i++) {
		a.at(s[i] - 'a')++;
	}



	for (int i = 0; i < 26; i++) {
		if (a.at(i) == 0) {
			cout << (char)('a' + i )<< endl;
			return 0;
		}
	}
	cout << "None" << endl;
	return 0;


}