#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void agc_a_bbq_easy(void) {
	int n;
	cin >> n;
	vector<int>l(n * 2);
	for (int i = 0; i < n * 2; i++) {
		cin >> l[i];
	}
	sort(l.begin(), l.end());
	int sum = 0;
	for (int i = 0; i < n * 2; i += 2) {
		sum += l[i];
	}
	cout << sum << endl;
}

int main()
{
    agc_a_bbq_easy();
    return 0;
}