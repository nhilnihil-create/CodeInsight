#include<iostream>
#include<vector>
#include<algorithm>
#include<complex>
#include<string>
#include<string.h>
using namespace std;
typedef long long int llint;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	char s[13];
	cin >> s;
	rep(i, 4) {
		cout << s[i];
	}
	cout << " ";
	rep(i, 8) {
		cout << s[i + 4];
	}
	cout << endl;
	return 0;
}
