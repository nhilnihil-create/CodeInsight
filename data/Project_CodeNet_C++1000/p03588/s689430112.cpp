#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int mod = 1000000007;
#define ll long long

int main()
{
	int N;
	cin >> N;
	ll A, B;
	ll m1 = 0, m2 = mod, pmin = mod;
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		m1 = max(m1, A);
		m2 = min(m2, A);
		pmin = min(pmin, B);
	}
	ll an = pmin;
	//cout << an << endl;
	an += m2 - 1;
	//cout << an << endl;
	an += m1 - m2 + 1;
	cout << an << endl;
}
