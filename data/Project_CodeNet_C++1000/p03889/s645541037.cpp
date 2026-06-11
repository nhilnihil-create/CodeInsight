#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define rep(i,a,b,k) for(register ll i=a;i<=b;i+=k)
#define drep(i,a,b,k) for(register ll i=a;i>=b;i-=k)
#define ll long long
#define mod 1000000007
using namespace std;
char a[100005];
int len;
bool flag=1;
int main()
{
	scanf("%s",&a);
	len=strlen(a)-1;
	if(!(len&1))
		puts("No"),exit(0);
	for(int i=0,j=len;i<j;i++,j--)
	{
		if((a[i]=='p'&&a[j]=='q')||(a[i]=='q'&&a[j]=='p')||(a[i]=='d'&&a[j]=='b')||(a[i]=='b'&&a[j]=='d'));
		else
		{
			flag=0;
			break;
		}
	}
	if(flag)
		puts("Yes"),exit(0);
	puts("No");
}