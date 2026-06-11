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
	int N;
	cin >> N;

	vector<int> a(N,0);
	for (int i = 0; i < N; ++i){
		cin >> a[i];
	}

	int counts = 0;
	for (int i = 0; i < N; ++i){
		int j = a[i];
		if (a[j-1] -1 == i){
			++counts;
		}
	}

	cout << counts / 2 << endl;

	return 0;
}