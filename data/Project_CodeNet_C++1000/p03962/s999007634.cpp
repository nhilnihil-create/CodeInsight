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
	set<int> paint;

	for (int i = 0; i < 3; ++i){
		int ptmp;
		cin >> ptmp;
		paint.insert(ptmp);
	}

	cout << paint.size() << endl;

	return 0;
}