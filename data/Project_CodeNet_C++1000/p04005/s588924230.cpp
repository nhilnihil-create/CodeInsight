#include <iostream>
#include <algorithm>
using namespace std;
long long a, b, c,ans;

int main()
{
	cin >> a >> b >> c;
	long long ab = a * b, ac = a * c, bc = b * c;
	long long t = ab, h = c;
	if (t > ac) {
		t = ac, h = b;
	}
	if (t > bc) {
		t = bc, h = a;
	}
	long long half = h / 2;

	ans = t * (h-2*half);
	cout << ans << endl;
}

