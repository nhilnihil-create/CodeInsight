#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
#include <map>
#include<cmath>
#include <queue>
#include <numeric>

using lli = long long int;
int inf = 1000000007;
using namespace std;

lli N, A, B, C, D;

int main()
{
	cin >> N >> A >> B >> C >> D;
	lli s = abs(A - B);
	//何回Cを足して何回Dを足したか
	for (lli i = 0; i < N; i++) {
		lli a = D * i - C * (N - 1 - i);
		lli b = C * i - D * (N - 1 - i);
		if (b <= s && s <= a) { cout << "YES" << endl; return 0; }
	}
	cout << "NO" << endl;
	return 0;
}