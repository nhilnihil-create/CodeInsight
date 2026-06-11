
//#pragma warning(disable : 4996)
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<stdio.h>
#include<map>
#include<set>
#include<limits.h>
#include<list>
#include <cassert>
#include<sstream>
#include <bitset>
using namespace std;
using ll = long long int;
using uint = unsigned int;


int main() {
	ll N, A, B;
	cin >> N >> A >> B;
	ll ans;
	if
		(A > B || A != B && N < 2)ans = 0;
	else
		if (A == B) ans = 1;
		else
		{
			ans = (N - 1) * B + A - (N - 1) * A - B + 1;
		}
	cout << ans;
	return 0;
} 



