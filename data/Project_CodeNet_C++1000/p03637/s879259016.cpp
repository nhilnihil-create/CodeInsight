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

	// vector<long long> a(N, 0);

	int num4 = 0;
	int numOdd = 0;
	for (int i = 0; i < N; ++i){
		long long curValue = 0;
		cin >> curValue;
		
		if (curValue % 4 == 0){
			++num4;
		}
		else if (curValue % 2 != 0){
			++numOdd;
		}
	}

	if (N % 2 != 0){ // 全体が奇数個の場合
		if (num4 >= numOdd - 1){
			cout << "Yes" << endl;
			return 0;
		}
	}
	else {
		if (num4 >= numOdd){
			cout << "Yes" << endl;
			return 0;
		}
	}
		
	cout << "No" << endl;

	return 0;
}