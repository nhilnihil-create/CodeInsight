#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<map>
#define ran(x) (x).begin(),(x).end()
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	for(int i = 1;i<101; ++i) {
		int d=a * i;
		if(d % b == c)
			return cout << "YES" << endl, 0;
	}
	cout << "NO" << endl;
}