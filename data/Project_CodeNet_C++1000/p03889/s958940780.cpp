#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
char a[100007],b[100007];
int main()
{
	scanf("%s",a);
	int len=strlen(a);
	for(int i=0;i<(len/2);i++)
		{
			b[i]=a[len-i-1];
			b[len-i-1]=a[i];
		}
	for(int i=0;i<len;i++)
		{
			if(b[i]=='b')
				{
				b[i]='d';
				continue;
				}
			if(b[i]=='d')
				{
				b[i]='b';
				continue;
				}
			if(b[i]=='p')
					{
				b[i]='q';
				continue;
				}
			if(b[i]=='q')
				{
				b[i]='p';
				continue;
				}
		}
	int k=0;
	for(int i=0;i<len;i++)
		{
			if(a[i]==b[i])
				continue;
			else
				{
					k=1;
					break;
				}
		}
	if(k==0)
		cout<<"Yes";
	else
		cout<<"No";
}