#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

char c[22];
int len;

bool ask(int q){
	printf("? ");
	for(int i = q; i > 0; --i) printf("%c",c[i]);
	puts("");fflush(stdout);
	char s[6];
	scanf("%s",&s);
	return s[0] == 'Y';
}

int main(){
//	freopen("input.inp", "r", stdin);
	int len = -1;
	for(int i = 1; i <= 10; ++i){
		c[i] = '1';
		if (!ask(i)){
			len = i - 1;
			break;
		}
		c[i] = '0';
	}
	if (len == -1){
		for(int i = 1; i <= 10; ++i){
			c[i] = '9';
			if (ask(i)){
				len = i;
				break;
			}
		}
	}
	for(int i = 1; i <= len + 1; ++i) c[i] = '9';
	for(int i = len + 1; i > 1; --i){
		int l = (len + 1) == i, r = 9;
		while (l <= r){
			int md = (l + r) >> 1;
			c[i] = char(md + '0');
			if (!ask(len + 1)) l = md + 1;
			else r = md - 1;
		}
		c[i] = char(l + '0');
	}
	printf("! ");
	for(int i = len + 1; i > 1; --i) printf("%c", c[i]);
	puts("");fflush(stdout);
	return 0;
}