
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
	string S;

	cin >> S;

	set<char> set1(S.begin(), S.end());

	if (set1.size() != S.size()){
		cout << "no" << endl;
	}
	else {
		cout << "yes" << endl;
	}

	return 0;
}