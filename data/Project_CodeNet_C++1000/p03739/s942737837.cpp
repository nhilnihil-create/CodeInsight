#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
using ll = long long;
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	rep(i, n) scanf("%d", &a[i]);

	ll temp = 0;

	//+-
	ll pm = 0;
	rep(i, n) {
		temp = temp + a[i];
		if(i % 2 == 0) {
			if(temp <= 0) {
				pm = pm + 1 - temp;
				temp = 1;
			}
		}
		else {
			if(temp >= 0) {
				pm = pm + 1 + temp;
				temp = -1;
			}
		}
	}

	//-+
	ll mp = 0;
	temp = 0;
	rep(i, n) {
		temp = temp + a[i];
		if(i % 2 == 1) {
			if(temp <= 0) {
				mp = mp + 1 - temp;
				temp = 1;
			}
		}
		else {
			if(temp >= 0) {
				mp = mp + 1 + temp;
				temp = -1;
			}
		}
	}

	printf("%lld\n", min(pm, mp));
	return 0;
}