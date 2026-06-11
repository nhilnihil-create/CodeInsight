#include<bits/stdc++.h>
using namespace std;

char s[100005];

int main()
{
	scanf("%s",s);
	int len=strlen(s);
	if(len%2==1) {
		printf("No");
		return 0;
	}
	for(register int i=0;i<=len/2;i++) {
		int flag=0;
		if(s[i]=='b') if(s[len-i-1]!='d') flag=1;
		if(s[i]=='d') if(s[len-i-1]!='b') flag=1;
		if(s[i]=='p') if(s[len-i-1]!='q') flag=1;
		if(s[i]=='q') if(s[len-i-1]!='p') flag=1;
		if(flag) {
			printf("No");
			return 0;
		} 
	}
	printf("Yes");
} 