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
#if 0
int Work2()
{
	int N;
	cin >> N;

	vector<int> a(N, 0);

	int cnt = 0;
	int maxV = 0;
	int minV = 0;
	for (int i = 0; i < N; ++i){
		int j;
		cin >> j;
		a[i] = j;
		maxV = max(maxV, j);
		minV = min(minV, j);
		// if (j - 1 == )
		
	}
	int maxC = 0;
	for (int i = minV - 1; i <= maxV; ++i){
		int cnt = 0;
		for (int j = 0; j < N; ++j){
			if (a[j] == i || (a[j] - 1 == i) || (a[j] + 1 == i)){
				++cnt;
			}
		}
		maxC = max(maxC, cnt);
	}
	cout << maxC << endl;
	//max = max(a.begin(), a.end());


	return 0;
}
#endif
int main()
{
	int N;
	cin >> N;

	vector<int> a(N, 0);
	map<int, int> num;

	// int cnt = 0;
	// int maxV = 0;
	// int minV = 0;
	for (int i = 0; i < N; ++i){
		int j;
		cin >> j;

		for (int k = -1; k <= 1; ++k){
			int curNum = j + k;
			if (num.count(curNum) == 0){
				num[curNum] = 1;
			}
			else{
				++num[curNum];
			}
		}
	}

	int maxC = 0;
	for (auto& elem : num){
		maxC = max(maxC, elem.second);

	}
	
	cout << maxC << endl;
	//max = max(a.begin(), a.end());


	return 0;
}