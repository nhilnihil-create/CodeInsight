#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>


using namespace std;


int main() {
	vector<int>a(100002);
	int N, tmp;
	cin >> N;

	for (int i = 0; i <= 100001 ; i++) {
		a[i] = 0;
	}


	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp > 0) {
			a[tmp - 1]++;
		}
		a[tmp]++;
		a[tmp + 1]++;
	}

	int MAX = 0;
	
	for (int i = 0; i <= 100001; i++) {
		MAX = max(a[i], MAX);
	}

	cout << MAX;

	return 0;
}
