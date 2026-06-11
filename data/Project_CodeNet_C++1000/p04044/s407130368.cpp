#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int test,l;
	cin >> test >> l;
	string t;
	vector<string> temp;
	for(int i = 0;i<test;i++) {
		cin >> t;
		temp.push_back(t);	
	}
	sort(temp.begin(), temp.end());
	for(int i = 0 ;i<test;i++) {
		cout << temp[i];
	}
}	