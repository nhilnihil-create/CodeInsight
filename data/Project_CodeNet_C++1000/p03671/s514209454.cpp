#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	vector<int>a(3);
	for (int i = 0; i < 3; i++)cin >> a.at(i);
	sort(a.begin(), a.end());
	cout << a.at(0)+a.at(1) << endl;
}