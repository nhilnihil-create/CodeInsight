
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>
#include<deque>
#include<list>


using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;
const int BIG_INT = 1000000000;



int main() {
	int n;
	cin >> n;
	vector<int> l(2 * n);
	for (int i = 0; i < 2 * n;i++) {
		cin >> l[i];
	}

	sort(l.begin(), l.end());
	int sum = 0;
	for (int i = 0; i < 2 * n;i += 2) {
		sum += l[i];
	}
	cout << sum << endl;
}

