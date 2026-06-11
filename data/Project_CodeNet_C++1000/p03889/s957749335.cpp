#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>
#include <iomanip>
#include <vector>
#include <queue>
#include <functional>
#include <random>
#include <time.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
int main() {
	string s;
	cin >> s;
	if (s.size() % 2)cout << "No" << endl;
	else {
		for (int i = 0; i < s.size() / 2; i++) {
			if ((s[i] == 'p'&&s[s.size() - 1 - i] == 'q') || (s[i] == 'q'&&s[s.size() - 1 - i] == 'p') || (s[i] == 'd'&&s[s.size() - 1 - i] == 'b') || (s[i] == 'b'&&s[s.size() - 1 - i] == 'd'));
			else {
				cout << "No" << endl;
				return 0;
			}
		}
		cout << "Yes" << endl;
	}
	return 0;
}
