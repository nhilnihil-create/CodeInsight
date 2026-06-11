#include<iostream>
#include<complex>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
typedef long long int llint;
#define rep(i,n) for(int i=0;i<n;i++)
int main() {
	char s[110];
	cin >> s;
	if (strlen(s) < 4) {
		cout << "No" << endl;
		return 0;
	}
	if (s[0] == 'Y'&&s[1] == 'A'&&s[2] == 'K'&&s[3] == 'I') {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}