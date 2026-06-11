#include<bits/stdc++.h>
using namespace std;
int main () {
	vector<string> a;
	int n, l;
	cin >> n >> l;
	string s;
	for (int i=0; i<n; i++) {
		cin >> s;
		a.push_back(s);
	}
	sort(a.begin(), a.end());
	for (int i=0; i<a.size();i++) {
		cout << a[i];
	}
	return 0;
}