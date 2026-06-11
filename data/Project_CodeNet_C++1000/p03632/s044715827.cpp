#include <iostream>
#include <vector>
#include<map>
#include<string>
#include<algorithm>
#include<sstream>
#include<cmath>
using namespace std;


int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a >= c&&b<=d) {
		cout << b - a;
	}
	else if (a <= c && b >= d) {
		cout << d - c;
	}
	else if (a <= c && b <= d&&c<=b) {
		cout << b - c;
	}
	else if(a>=c&&b>=d&&a<=d){
		cout << d - a;
	}
	else {
		cout << 0;
	}
}