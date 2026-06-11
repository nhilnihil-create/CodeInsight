#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int n,l;
	string s[100];
	string ans;
	
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	sort(s, s + n);


	for (int i = 0; i < n; i++) {
		ans += s[i];
	}

	cout << ans << endl;
	
	return 0;
}