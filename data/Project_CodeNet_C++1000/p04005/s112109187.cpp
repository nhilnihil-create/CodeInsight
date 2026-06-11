#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	long long a, b, c,mx=0,tmp1,tmp2;
	cin >> a >> b >> c;
	mx = max(max(a, b), c);
	if (a == mx)tmp1 = b, tmp2 = c;
	else if (b == mx)tmp1 = a, tmp2 = c;
	else if (c == mx)tmp1 = a, tmp2 = b;
	if (mx%2==0) cout << 0 << endl;
	else cout << tmp1 * tmp2 << endl;
	return 0;
}