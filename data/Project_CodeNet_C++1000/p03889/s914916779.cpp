#include<stdio.h>
#include<string.h>

inline char transform(char x) {
	if(x == 'b') return 'd';
	if(x == 'd') return 'b';
	if(x == 'q') return 'p';
	if(x == 'p') return 'q';
	return 0;
}

char s[1000005];
int main(int argc, char** args) {
	scanf("%s", s);
	int len = strlen(s) - 1;
 	for(int i = 0;s[i];i++) {
		if(transform(s[i]) != s[len - i]) {
			return printf("No\n"), 0;
		}
	}
	printf("Yes\n");
	return 0;
}