#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL a, b;

LL f(LL x, LL y) {
	LL z = x/y;
	if(x%y == 0) return 2*x - y;
	return 2*z*y + f(y, x%y);
}

int main() {
	cin>>a>>b;
	cout<<a + f(b, a - b)<<endl;
	return 0;
}