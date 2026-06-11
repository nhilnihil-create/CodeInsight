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
	int a, b;
	cin >> a >> b;
	string str;
	int x, y;
	rep(i, a) {
		rep(j, b) {
			cin >> str;
			if (str == "snuke") {
				x = i;
				y = j;
			}
		}
	}
	cout << (char)('A' + y) << x + 1 << endl;
	return 0;
}