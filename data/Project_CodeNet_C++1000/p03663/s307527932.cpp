#include <bits/stdc++.h>
using namespace std;

#define mp(x, y) make_pair((x), (y))

typedef long long ll;

ll ten[42];

int dig;

int main()
{
	ten[1]=1;
	for(int i=2; i<=14; i++) ten[i]=10*ten[i-1];

	dig=-1;
	for(int i=2; i<=10; i++) {
		printf("? %lld\n", ten[i]);
		fflush(stdout);
		char c;
		scanf(" %c", &c);
		if(c=='N') {
			dig=i-1;
			break;
		}
	}
	if(dig==-1) {
		for(int i=9; i>=1; i--) {
			printf("? %lld\n", ten[i+1]-1);
			fflush(stdout);
			char c;
			scanf(" %c", &c);
			if(c=='N') {
				printf("! %lld\n", ten[i+1]);
				fflush(stdout);
				return 0;
			}
		}
		printf("! 1\n");
		fflush(stdout);
		return 0;
	}

	ll l=ten[dig];
	ll r=ten[dig+1]-1;

	while(l<r) {
		ll m=(l+r)/2;
		printf("? %lld\n", 10*m);
		fflush(stdout);
		char c;
		scanf(" %c", &c);
		if(c=='Y') r=m;
		else l=m+1;
	}
	printf("! %lld\n", l);
	fflush(stdout);

	return 0;
}