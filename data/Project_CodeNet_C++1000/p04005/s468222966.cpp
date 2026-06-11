#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long ll;

ll a[5];

int main() {
	cin >> a[1] >> a[2] >> a[3];
	sort(a + 1, a + 4);
	if (!(a[1] & 1) || !(a[2] & 1) || !(a[3] & 1)) {
		cout << 0 << endl;
	}
	else {
		cout << a[1] * a[2] << endl;
	}
	return 0;
}