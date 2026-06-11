#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> s(n);
	int sum = 0;
	rep(i, n) {
		scanf("%d", &s[i]);
		sum += s[i];
	}
	if(sum % 10 == 0) {
		sort(s.begin(), s.end());
		rep(i, n) {
			if (s[i] % 10) { //s[i]が10の倍数でなければ
				sum -= s[i];
				break;
			}
		}
	}
	if(sum % 10 == 0) sum = 0;
	printf("%d\n", sum);
	return 0;
}