
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
	int N; cin >> N;
	unsigned long long a = 1;
	for (int i = 1; i <= N; ++i) {
		a = a * i % (1000 * 1000 * 1000 + 7);
	}
	cout << a << endl;
	return 0;
}