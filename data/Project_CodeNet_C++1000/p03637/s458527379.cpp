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
	int count4 = 0;
	int count2 = 0;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		if (a % 4 == 0)count4++;
		else if (a % 2 == 0) count2++;
	}
	
	int n = N - max(0, count2 - 1);
	if (count2 % 2 == 0) {

	}
	n = n / 2;

	if (n <= count4) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}
