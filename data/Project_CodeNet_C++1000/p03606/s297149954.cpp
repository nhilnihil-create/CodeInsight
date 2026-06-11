#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N,l,r,i,ans = 0;
	cin >> N;

	for (i = 0; i < N; i++){
		cin >> l >> r;
		ans = (ans + ((r - l) + 1));
	}
	cout << ans << endl;
}