#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

typedef long long ll;

int main() {
	ll n, m;
	cin >> n >> m;
	ll num1 = n,num2=m/2;
	if (num2 < num1) {
		cout << num2 << endl;
	}
	else {
		ll num3 = m - num1 * 2;
		cout << num3 / 4 + num1 << endl;
	}
	return 0;
}