#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <functional>
#define rep(i,n,m) for(int i=n;i<(int)(m);i++)
using namespace std;

int main() {
	int N, i = 1, j;
	vector<long long> NN;
	cin >> N;

	while (N >= 0) {
		NN.push_back(i);
		N -= i;
		//cout << i << endl;
		i++;
	}
	for (j = 0; j < i - 1; j++) {
		if (NN[j] != N*-1) {
			cout << NN[j] << endl;
		}
	}

	return 0;
}