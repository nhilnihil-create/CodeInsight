#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool check(ll ans)
{
	ans++;
	while(ans % 10 == 0) ans /= 10;
	return ans == 1;
}

int main()
{
	ll ans = -1;
	for(ll l = 1e9, r = 1e10 - 1; l <= r; ) {
		ll md = (l + r) / 2;
		printf("? %lld\n", md), fflush(stdout);
		char ch[5];
		scanf("%s", ch);
		if(ch[0] == 'Y') ans = md, r = md - 1; else l = md + 1;
	}
	for(; ans ;) {
		printf("? %lld\n", ans + 1), fflush(stdout);
		char ch[5];
		scanf("%s", ch);
		if(!check(ans) && ch[0] == 'N' || check(ans) && ch[0] == 'Y') {printf("! %lld\n", ans * 10), fflush(stdout); return 0;}
		if(ans % 10 != 0) {printf("! %lld\n", ans), fflush(stdout); return 0;}
		ans /= 10;
	}
	/*ll n = (long long) (1e17) - 1;
	for(ll i = 1, o = 1e16; ; o /= 10, i++) {
		int ans = -1;
		/*if(i != 1) {
			printf("? %lld\n", n);
			fflush(stdout);
			char ch[5];
			scanf("%s", ch);
			if(ch[0] == 'Y') {printf("! %lld\n", n / o / 10); fflush(stdout); return 0;}
		}
		for(int l = 0, r = 9; l <= r; ) {
			int md = (l + r) / 2;
			printf("? %lld\n", n + md * o);
			fflush(stdout);
			char ch[5];
			scanf("%s", ch);
			if(ch[0] == 'Y') ans = md, r = md - 1; else l = md + 1;
		}
		if(ans == -1) {printf("! %lld\n", n / o / 10); fflush(stdout); return 0;}
		n += ans * o;
	}*/
	return 0;
}