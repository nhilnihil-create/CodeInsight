#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<set>
#include<map>

using namespace std;
long long MOD = 1000000007LL;
const double PI = 3.14159265358979323846;
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define endl "\n"

int main() {
	int N;
	cin >> N;

	vector<int> A(N);
	list<int> lst;
	bool flags = true;
	if (N % 2 == 0) {
		flags = true;
	}
	else {
		flags = false;
	}
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		if (flags) {
			lst.push_back(a);
		}
		else {
			lst.push_front(a);
		}

		flags = !flags;
	}

	for (auto x : lst) {
		cout << x << " ";
	}

	cout << endl;
	return 0;
}