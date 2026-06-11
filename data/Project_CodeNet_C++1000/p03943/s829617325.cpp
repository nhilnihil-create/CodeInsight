#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	vector<int>abc(3);
	for (int i = 0; i < 3; i++)cin >> abc.at(i);
	sort(abc.begin(), abc.end());
	if (abc.at(0) + abc.at(1) == abc.at(2))cout << "Yes" << endl;
	else cout << "No" << endl;

}