#include <iostream>
#include <cstdio>
using namespace std;

int n, mx, i, t, s, ans;
int main()
{
	cin >> n;
	for (i =1; i <= n; i++) {
			scanf("%d",&t);
			if (t == i) s++;
			else {
					if (s > 0) ans += (s + 1) / 2;
					s = 0;
			}
	}
					if (s > 0) ans += (s + 1) / 2;
	cout << ans;
    return 0;
}
