#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <new>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <tuple>
#include<map>

using namespace std;
int main() {
	string s1, s2, s3;

	cin >> s1 >> s2 >> s3;

	s1 = toupper(s1.at(0));
	s2 = toupper(s2.at(0));
	s3 = toupper(s3.at(0));

	cout << s1 << s2 << s3 << endl;
}