#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 100005;
char s[maxn];

int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	if (s[1] == s[n]) {
		if ((n - 2) & 1) puts("Second");
		else puts("First");
	} else {
		if ((n - 2) & 1) puts("First");
		else puts("Second");
	}
	return 0;
}