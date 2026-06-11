#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main(){	
	LL ai, ao, at, aj, al, as, az;
	scanf("%lld%lld%lld%lld%lld%lld%lld", &ai, &ao, &at, &aj, &al, &as, &az);
	LL ans = ai / 2 * 4 + ao * 2 + aj / 2 * 4 + al / 2 * 4;
	if (ai % 2 && aj % 2 && al % 2) ans += 6;
	else if (ai % 2 && aj % 2 && al > 0) ans += 2;
	else if (ai % 2 && aj > 0 && al % 2) ans += 2;
	else if (ai > 0 && aj % 2 && al % 2) ans += 2;
	printf("%lld", ans / 2);
	return 0;
}