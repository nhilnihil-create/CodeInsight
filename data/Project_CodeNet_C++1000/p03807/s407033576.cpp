#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <numeric>
#include <iterator>
using namespace std;

namespace {

}

int main()
{
	long long N = 0;
	cin >> N;
	
	// vector<long long> A(N, 0);

	int countEvn = 0;
	int countOdd = 0;

	for (int i = 0; i < N; ++i){
		int curValue = 0;
		cin >> curValue;
		if (curValue % 2 == 0) {
			++countEvn;
		}
		else {
			++countOdd;
		}
	}

	int rest = 0;
	if (countOdd % 2 != 0){
		// 奇数個なら奇数は残る。
		++rest; // 奇数個
	}
	else{
		++countEvn; // 偶数が1つ増える。 
	}

	if (countEvn > 0){
		// 1個残る。
		++rest;
	}

	if (rest == 1){
		cout << "YES" << endl;
		return 0;
	}


	cout << "NO" << endl;


	return 0;
}
