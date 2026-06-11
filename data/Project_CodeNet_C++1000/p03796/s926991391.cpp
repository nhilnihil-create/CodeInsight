#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;

int main() {
	long long n;
	cin >> n;

	long long power = 1;
	for (int i = 1; i <= n; ++i) {
		power = power * i % 1000000007;
	}

	cout << power << endl;

	return 0;
}