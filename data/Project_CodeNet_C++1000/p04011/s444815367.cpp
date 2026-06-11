#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, k, x, y;
	cin >> n >> k >> x >> y;
	int firstk = min(n, k);
	int remainingnights = n - min(n, k);
	cout << (long long)firstk*x + remainingnights*y;
}
