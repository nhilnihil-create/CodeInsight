#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, ss = "CODEFESTIVAL2016";
	cin >> s;
	int ct = 0, i;
	for (i = 0; i < 16; i++) {
		if (s[i] != ss[i])ct++;
	}
	cout << ct << "\n";

	return 0;
}

