#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	string in;
	string ans;

	cin >> in;

	for (int i = 0; i < in.size(); i++) {
		if (in[i] == '0')ans += '0';
		else if (in[i] == '1')ans += '1';
		else if (in[i] == 'B'&&ans.empty() == 0) {
			ans.pop_back();
		}
	}
	cout << ans<<endl;
	return 0;
}