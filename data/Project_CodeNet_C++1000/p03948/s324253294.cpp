#include <iostream>
#include <cstdio>
using namespace std;

int n, c, mn = 2e9, mx, md;
int main()
{
	int t;
	cin >> n >> t;
	while (n--) {
		scanf("%d", &t);
		if (t < mn) mn = t, mx = 0;
		if (t > mx) {
			mx = t;
			if (mx - mn > md) md = mx - mn, c = 0;
			if (mx - mn == md) c++;
		}
	}
    cout << c << endl;
    return 0;
}