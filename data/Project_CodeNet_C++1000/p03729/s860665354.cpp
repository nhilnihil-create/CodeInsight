#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
#include <iomanip>
#include <bitset>
#include <numeric>
#include <queue>
#include <map>
#include <cstdint>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
const long long mod = 1000000007;
typedef long long int ll;
typedef pair<ll, ll> P;
const vector<int> di = { -1, 0, 1, 0 };
const vector<int> dj = { 0, 1, 0, -1 };



int main() {

	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;


	if (s1.at(s1.size() - 1) == s2.at(0) && s2.at(s2.size() - 1) == s3.at(0)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	
	return 0;
}