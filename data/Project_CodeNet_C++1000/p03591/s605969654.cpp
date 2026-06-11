#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
	string S; cin >> S;
	if (S.length() < 4) cout << "No" << endl;
	else if (S.substr(0, 4) == "YAKI") cout << "Yes" << endl;
	else  cout << "No" << endl;
}