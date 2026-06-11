#include<bits/stdc++.h>
int main()
{
	char s[1000];
	char t[]="CODEFESTIVAL2016";
	gets(s);
	int flag=0;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]!=t[i])
		flag++;
	}
	printf("%d",flag);
	return 0;
}