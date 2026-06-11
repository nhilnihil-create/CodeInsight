#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
	ll N;
	cin >> N;
	vector<ll> a(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	ll count = 0;
	ll flag = 0;
	for (ll i = 0; i < N - 1; i++)
	{
		if (i == 0 || flag == 0) {
			if (a[i + 1] > a[i]) {
				flag = 1;
				count++;
			}
			else if (a[i + 1] == a[i]) {
				flag = 0;
			}
			else {
				flag = -1;
				count++;
			}
		}
		else if (flag == 1) {
			if (a[i + 1] < a[i]) {
				flag = 0;
				continue;
			}
		}
		else if (flag == -1) {
			if (a[i + 1] > a[i]) {
				flag = 0;
				continue;
			}
		}
	}
	if (flag == 0) {
		count += 1;
	}
	cout << count << endl;
	return 0;
}