#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<map>
#define ran(x) (x).begin(),(x).end()
using namespace std;
int main() {
	int64_t a, b, x,ans=0;
	cin >> a >> b >> x;
	if(x > 1 && a == 0)
		return cout << 1 + b / x - (a - 1) / x << endl, 0;
	cout << b / x - (a-1) / x << endl;
}