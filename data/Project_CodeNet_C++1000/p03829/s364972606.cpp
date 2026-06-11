
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

const int SIZE = 500;

int main() {
	int n;
	ll a, b;
	cin >> n >> a >> b;

	vector<int> x(n);

	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	ll cost = 0;
	for (int i = 1;i < n; i++) {
		cost += min((x[i] - x[i - 1])*a, b);
	}


	
	cout << cost << endl;
}
