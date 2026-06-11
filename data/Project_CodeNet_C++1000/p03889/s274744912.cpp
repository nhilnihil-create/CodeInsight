#include <bits/stdc++.h>
#define Max 1000005
using namespace std;
char a[Max];
int n;
bool check(int x)
{
	if(a[x]==a[n-x+1]&&a[x]!='d'&&a[x]!='p'&&a[x]!='q'&&a[x]!='b') return 1;
	if(a[x]=='d'&&a[n-x+1]=='b') return 1;
	if(a[x]=='b'&&a[n-x+1]=='d') return 1;
	if(a[x]=='q'&&a[n-x+1]=='p') return 1;
	if(a[x]=='p'&&a[n-x+1]=='q') return 1;
	return 0;
}
int main()
{
	scanf("%s",a+1);
	n=strlen(a+1);
	for(int i=1;i<=(n+1)/2;i++)
		if(!check(i)) puts("No"),exit(0);
	puts("Yes");
}