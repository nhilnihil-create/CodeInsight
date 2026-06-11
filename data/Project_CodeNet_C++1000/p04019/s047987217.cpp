#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	string s;
	cin >> s;
	int a[4] = { 0 };
	for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'E')a[0]=1;
			if (s[i] == 'W')a[1]=1;
			if (s[i] == 'S')a[2]=1;
			if (s[i] == 'N')a[3]=1;
	}
	if (a[0] == a[1] && a[2] == a[3]) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}