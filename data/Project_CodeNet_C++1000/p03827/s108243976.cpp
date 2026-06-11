#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	
	int x = 0;
	vector<int> v;
	v.push_back(x);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'I') {
			x++;
		}
		else {
			x--;
		}
		v.push_back(x);
	}
	cout << *max_element(v.begin(), v.end()) << endl;

	return 0;
}