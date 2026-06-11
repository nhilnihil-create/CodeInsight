#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	string res = "AXC";
	res[1] = s2[0];
	cout << res << endl;
}
