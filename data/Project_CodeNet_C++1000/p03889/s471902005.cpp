#include <stdio.h>
#include <string.h>
#define N 100001

char a[N];
char ha[128];

int main()
{	
	int i, l, j;
	
	scanf("%s", a);
	l = strlen(a);
	if(l & 1){
		puts("No");
		return 0;
	}
	ha['p'] = ha['q'] = 1, ha['d'] = ha['b'] = 2;
	
	for(i = 0, j = l - 1; i < j; i++, j--){
		if(ha[a[i]] != ha[a[j]] || a[i] == a[j]){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
		
	return 0;
}