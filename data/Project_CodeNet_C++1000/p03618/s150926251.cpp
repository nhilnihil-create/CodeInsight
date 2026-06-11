#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

void AGC019B()
{
	string A;
	cin >> A;
	size_t n = A.size();
	ll ct = 1;
	vi cts(26);
	for (size_t i = 0; i < n; ++i)
	{
		int m = A[i] - 'a';
		ct += i - cts[m];
		++cts[m];
	}
	cout << ct << endl;
}



int main()
{
	AGC019B();
	return 0;
}