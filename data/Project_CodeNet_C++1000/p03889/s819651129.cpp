#include<stdio.h>
#include<cstring>
char s[100005];
char f['z'];
int len;
int main(){
	f['b']='d';
	f['d']='b';
	f['p']='q';
	f['q']='p';
	scanf("%s",s+1);
	len=strlen(s+1);
	if (len&1){
		puts("No");
		return 0;
	}
	int p=len>>1;
	for (int i=1;i<=p;i++){
		if (f[s[i]]!=s[len-i+1]){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}