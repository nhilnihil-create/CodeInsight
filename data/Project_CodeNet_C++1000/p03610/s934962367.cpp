#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	string a;
	string st;
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if (i % 2 == 0) {
			st.push_back(a[i]);
		}
	}

	cout << st;
}