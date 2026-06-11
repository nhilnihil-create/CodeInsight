#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N, L;
	cin >> N >> L;
	vector<string> vec;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		vec.push_back(s);
	}
	sort(vec.begin(), vec.end());
	string res;
	for (string s : vec) {
		res += s;
	}
	cout << res << endl;
	return 0;


}