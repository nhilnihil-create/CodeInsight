#include <stdio.h>
#include <string.h>

int main(){
	char i[26], j[26], k[26];
	scanf("%s %s %s", &i, &j, &k);
	int a=strlen(i), b=strlen(j);
	if(i[a-1]==j[0] && j[b-1]==k[0]){
		 printf("YES\n");
	}
	else {
		printf("NO\n");
	}
	return 0;
}