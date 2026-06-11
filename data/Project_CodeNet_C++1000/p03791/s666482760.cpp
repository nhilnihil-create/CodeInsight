#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
ll n, c, x, ans = 1, M = 1e9 + 7;
int main()
{
	cin >> n;
	while (n--) {
		scanf("%d", &x);
		if (x >= c * 2 + 1) c++;
		else ans = ans * (c + 1) % M;
	}
	while (c) ans = ans * c-- % M;
    cout << ans << endl;
    return 0;
}